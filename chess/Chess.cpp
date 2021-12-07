/*
 * Chess.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: ubuntu
 */

#include "Chess.h"
#include "King.h"

void Chess::init() {
    loadGameResources(paths);

    board = resources[Resources::board];
    startScreen = resources[Resources::startScreen2];
    newGameBtn = new Button(340, 260, resources[Resources::newGameButton]);
    continueGameBtn = new Button(340, 330, resources[Resources::continueGameButton]);
    quitGameButton = new Button(660, 50, resources[Resources::quitGameButton]);
    quitGameButtonOnStartPage = new Button(340, 400, new Image(resources[Resources::quitGameButton]));
    saveGameBtn = new Button(660, 120, resources[Resources::saveGameButton]);

    createClock();
}

void Chess::draw() {
    if (currentState == State::WELCOME_SCREEN) {
        startScreen->draw(*renderer);

        newGameBtn->draw(*renderer);
        continueGameBtn->draw(*renderer);
        quitGameButtonOnStartPage->draw(*renderer);
    } else {
        board->draw(*renderer);

        for (Piece* piece : activePieces) {
            piece->draw(*renderer);
        }
        for (Piece* piece : passivePieces) {
            piece->draw(*renderer, currentRotation);
        }
        quitGameButton->draw(*renderer);
        saveGameBtn->draw(*renderer);
        clock->draw(*renderer);
        if (winnerText != nullptr) {
            winnerText->draw(*renderer);
        }

        for (Image* logLine : logImages) {
            logLine->draw(*renderer);
        }
        showLastTenMoves();
    }
}

void Chess::executeGameLogic() {
    if (currentState == State::INITIALIZE_BOARD) {
        setPiecesOnBoard();
        populatePiecesMap();
        currentState = State::WHITE;
        createClock();
    } else if (currentState == State::LOAD_BOARD_FROM_FILE) {

    } else if (currentState == State::WHITE) {
        clockStartTime = std::chrono::steady_clock::now();
        currentState = State::HUMAN;
        createClock();
    } else if (currentState == State::BLACK) {
        clockStartTime = std::chrono::steady_clock::now();
        currentState = State::COMPUTER;
    } else if (currentState == State::HUMAN) {
    	if (!selectedCell.isEmpty) {
    		if (isOwnPiece(getPieceOnCell(selectedCell))) {
    			selectedPiece = getPieceOnCell(selectedCell);
    			currentState = State::AVAILABLE_MOVES;
    		}
    	}
    	createClock();
    } else if (currentState == State::AVAILABLE_MOVES) {
    	availableMoves = selectedPiece->calculateMoves(piecesMap);

    	std::cout << "All the calculated moves for a piece are: " << availableMoves.size() << std::endl;
    	currentState = State::FILTER_OUTSIDE_OF_BOARD_MOVES;
    } else if (currentState == State::SELECTED) {
    	// We have to handle changing the piece
    	std::cout << "We have this many moves " << availableMoves.size() << std::endl;
    } else if (currentState == State::FILTER_OUTSIDE_OF_BOARD_MOVES) {
    	filterOutsideOfBoardMoves();
    	std::cout << "All the inside board moves for a piece are: " << availableMoves.size() << std::endl;
    	currentState = State::FILTER_PAWN_ATTACK_MOVES;
    } else if (currentState == State::FILTER_PAWN_ATTACK_MOVES) {
    	filterOutPawnAttackMoves();
    	std::cout << "All the pawn attack moves for a piece are: " << availableMoves.size() << std::endl;
    	currentState = State::FILTER_EXPOSE_KING_MOVES;
    } else if (currentState == State::FILTER_EXPOSE_KING_MOVES) {
    	filterOutExposeKingMoves();
    	std::cout << "All the expose king moves for a piece are: " << availableMoves.size() << std::endl;
    	currentState = State::FILTER_OCCUPIED_CELLS_MOVES;
    } else if (currentState == State::PUT_PIECE) {
    	if (putPiece()) {
			currentState = State::CALCULATE_CAPTURES;
    	}
    	createClock();
    } else if (currentState == State::FILTER_OCCUPIED_CELLS_MOVES) {
    	filterOutOccupiedCellsMoves();
    	std::cout << "All the occupied cells moves for a piece are: " << availableMoves.size() << std::endl;
    	currentState = State::PUT_PIECE;
    } else if (currentState == State::SWITCH_PLAYER) {
    	switchPlayer();
    } else if (currentState == State::COMPUTER) {
    	makeComputerMove();
    	createClock();
    } else if (currentState == State::CALCULATE_CAPTURES) {
    	calculateCaptures();
    	currentState = State::SWITCH_PLAYER;
    } else if (currentState == State::CHECKMATE) {
        movesLog.clear();
    	std::cout << "Player " << (winner == Side::White ? "White" : "Black") << " wins by checkmate" << std::endl;

        currentRotation += 3;

        if (currentRotation > 360) {
            currentState = State::QUIT;
        }

        SDL_Color fontColor = {
                .r =  255,
                .g =  0,
                .b =  0,
                .a = static_cast<Uint8>(currentRotation % 255)
        };

        auto* winnerTextTexture = new Texture(*renderer, font, winner == Side::White ? "White wins" : "Black wins", fontColor);
        winnerText = new Image(*winnerTextTexture);
        winnerText->put(100, 660);
    } else if (currentState == State::QUIT) {
        clearSelection();
        deinit();
    }
}

void Chess::handleLeftMouseClick() {
	int32_t x, y;
	SDL_GetMouseState(&x, &y);
	Cell clickedCell = {x / Piece::PIECE_WIDTH, y / Piece::PIECE_HEIGHT, false};
    bool isQuitGameButtonClicked = quitGameButton->isClicked({x, y});
    bool isSaveGameButtonClicked = saveGameBtn->isClicked({x, y});

    if (isQuitGameButtonClicked) {
        currentState = State::QUIT;
    } else if (isSaveGameButtonClicked) {
        saveGame();
        currentState = State::QUIT;
    } else if (currentState == State::HUMAN) {
		selectedCell = clickedCell;
	} else if (currentState == State::PUT_PIECE) {
		Piece* targetCellPiece = getPieceOnCell(clickedCell);

        if (targetCellPiece != nullptr && selectedPiece->getRank() == Rank::KING && targetCellPiece->getRank() == Rank::ROOK &&
            selectedPiece->getSide() == targetCellPiece->getSide()) {
            bool performedOk = performCastling(selectedPiece, targetCellPiece);

            if (!performedOk) {
                return;
            }

            clockStartTime = std::chrono::steady_clock::now();
            createClock();
            currentState = State::SWITCH_PLAYER;
            return;
        }

		if (targetCellPiece != nullptr && targetCellPiece->getSide() == selectedPiece->getSide()) {
			selectedCell = clickedCell;
			currentState = State::HUMAN;
			return;
		}

		targetCell = clickedCell;
	} else if (currentState == State::WELCOME_SCREEN) {
        bool isExitGameBtnClicked = quitGameButtonOnStartPage->isClicked({x, y});

        if (isExitGameBtnClicked) {
            quit = true;
        }

        bool isNewGameBtnClicked = newGameBtn->isClicked({x, y});

        if (isNewGameBtnClicked) {
            currentState = State::INITIALIZE_BOARD;
        }

        bool isContinueGameClicked = continueGameBtn->isClicked({x, y});

        if (isContinueGameClicked) {

        }
    }
}

Chess::Chess() : Engine("Chess") {
    currentState = State::WELCOME_SCREEN;
    isWhiteHuman = true;
    currentSide = Side::White;
}

void Chess::setPiecesOnBoard() {
    for (uint32_t colIdx = 0; colIdx < (uint32_t)8; colIdx++) {
        activePieces.push_back(new Pawn(static_cast<int32_t>(colIdx), 6, Side::White, new Image(resources[Resources::whitePawn])));
        passivePieces.push_back(new Pawn(static_cast<int32_t>(colIdx), 1, Side::Black, new Image(resources[Resources::blackPawn])));
    }

    activePieces.push_back(new Rook(0, 7, Side::White, new Image(resources[Resources::whiteRook])));
    activePieces.push_back(new Knight(1, 7, Side::White, new Image(resources[Resources::whiteKnight])));
    activePieces.push_back(new Bishop(2, 7, Side::White, new Image(resources[Resources::whiteBishop])));
    activePieces.push_back(new King(4, 7, Side::White, new Image(resources[Resources::whiteKing])));
    activePieces.push_back(new Queen(3, 7, Side::White, new Image(resources[Resources::whiteQueen])));
    activePieces.push_back(new Bishop(5, 7, Side::White, new Image(resources[Resources::whiteBishop])));
    activePieces.push_back(new Knight(6, 7, Side::White, new Image(resources[Resources::whiteKnight])));
    activePieces.push_back(new Rook(7, 7, Side::White, new Image(resources[Resources::whiteRook])));

    passivePieces.push_back(new Rook(0, 0, Side::Black, new Image(resources[Resources::blackRook])));
    passivePieces.push_back(new Knight(1, 0, Side::Black, new Image(resources[Resources::blackKnight])));
    passivePieces.push_back(new Bishop(2, 0, Side::Black, new Image(resources[Resources::blackBishop])));
    passivePieces.push_back(new King(4, 0, Side::Black, new Image(resources[Resources::blackKing])));
    passivePieces.push_back(new Queen(3, 0, Side::Black, new Image(resources[Resources::blackQueen])));
    passivePieces.push_back(new Bishop(5, 0, Side::Black, new Image(resources[Resources::blackBishop])));
    passivePieces.push_back(new Knight(6, 0, Side::Black, new Image(resources[Resources::blackKnight])));
    passivePieces.push_back(new Rook(7, 0, Side::Black, new Image(resources[Resources::blackRook])));
}

Piece *Chess::getPieceOnCell(Cell cell) {
    for (Piece* piece : activePieces) {
        if (piece->getCol() == cell.col && piece->getRow() == cell.row) {
            return piece;
        }
    }

    for (Piece* piece : passivePieces) {
        if (piece->getCol() == cell.col && piece->getRow() == cell.row) {
            return piece;
        }
    }

    return nullptr;
}

bool Chess::isOwnPiece(Piece *piece) {
    return piece != nullptr && piece->getSide() == currentSide;
}

void Chess::populatePiecesMap() {
	piecesMap.clear();
	std::vector<Piece*> allPieces = activePieces;
	allPieces.insert(std::end(allPieces), std::begin(passivePieces), std::end(passivePieces));

	for (Piece* p : allPieces) {
		Cell key = {p->getCol(), p->getRow()};
		piecesMap[key] = p;
	}
}

void Chess::filterOutsideOfBoardMoves() {
	std::vector<Cell> insideBoardMoves;

	for (Cell& c : availableMoves) {
		if (c.col >= 0 && c.col <= 7 && c.row >= 0 && c.row <= 7) {
			insideBoardMoves.push_back(c);
		}
	}

	availableMoves = insideBoardMoves;
}

void Chess::filterOutPawnAttackMoves() {
	if (selectedPiece->getRank() == Rank::PAWN) {
		std::vector<Cell> moves;

		Cell oneForwardMove = {selectedPiece->getCol(), selectedPiece->getRow() + (selectedPiece->getSide() == Side::White ? -1 : 1)};
		Piece* oneForwardCellPiece = getPieceOnCell(oneForwardMove);

		if (oneForwardCellPiece == nullptr) {
			moves.push_back(oneForwardMove);

			Cell twoForwardMove = {selectedPiece->getCol(), selectedPiece->getRow() + (selectedPiece->getSide() == Side::White ? -2 : 2)};
			Piece* twoForwardCellPiece = getPieceOnCell(twoForwardMove);

			if (twoForwardCellPiece == nullptr && ((Pawn*)selectedPiece)->isOnInitialPosition()) {
				moves.push_back(twoForwardMove);
			}
		}

		Cell attackLeftCell = {selectedPiece->getCol() - 1, selectedPiece->getRow() + (selectedPiece->getSide() == Side::White ? -1 : 1)};
		Piece* attackLeftCellPiece = getPieceOnCell(attackLeftCell);

		if (attackLeftCellPiece != nullptr && attackLeftCellPiece->getSide() != selectedPiece->getSide()) {
			moves.push_back(attackLeftCell);
		}

		// en passant
        if (lastMove.rank == Rank::PAWN && lastMove.previous.row == (lastMove.side == Side::Black ? 1 : 6) &&
            lastMove.current.row == (lastMove.side == Side::Black ? 3 : 4) &&
            lastMove.current.col + 1 == selectedPiece->getCol() &&
			lastMove.current.row == selectedPiece->getRow()) {
            moves.push_back(attackLeftCell);
        }

		Cell attackRightCell = {selectedPiece->getCol() + 1, selectedPiece->getRow() + (selectedPiece->getSide() == Side::White ? -1 : 1)};
		Piece* attackRightCellPiece = getPieceOnCell(attackRightCell);

		if (attackRightCellPiece != nullptr && attackRightCellPiece->getSide() != selectedPiece->getSide()) {
			moves.push_back(attackRightCell);
		}

		if (lastMove.rank == Rank::PAWN && lastMove.previous.row == (lastMove.side == Side::Black ? 1 : 6) &&
			lastMove.current.row == (lastMove.side == Side::Black ? 3 : 4) &&
			lastMove.current.col - 1 == selectedPiece->getCol() &&
			lastMove.current.row == selectedPiece->getRow()) {
			moves.push_back(attackRightCell);
		}

		availableMoves = moves;
	}
}

void Chess::filterOutExposeKingMoves() {
	// for all the moves, check if we move them our king will be attacked from a piece of the enemy.
	std::vector<Cell> moves;
	Piece* kingPiece;
	Cell previousPos = selectedPiece->getCell();

	for (Piece* ownPieces : activePieces) {
		if (ownPieces->getRank() == Rank::KING) {
			kingPiece = ownPieces;
			break;
		}
	}

	for (Cell& move : availableMoves) {
		bool isExposingTheKing = false;
		// Let's move the piece and regenerate the map
		selectedPiece->move(move);
		populatePiecesMap();

		// For each enemy piece, check if it can attack our king
		// if it cannot, add the move
		for (Piece* piece : passivePieces) {
			std::vector<Cell> enemyPieceMoves = piece->calculateMoves(piecesMap);

			for (Cell& enemyMove : enemyPieceMoves) {
				if (enemyMove.col == kingPiece->getCol() && enemyMove.row == kingPiece->getRow()) {
					isExposingTheKing = true;
				}
			}
		}

		if (!isExposingTheKing) {
			moves.push_back(move);
		}
	}

	availableMoves = moves;
	this->selectedPiece->move(previousPos);
	populatePiecesMap();
}

void Chess::filterOutOccupiedCellsMoves() {
	std::vector<Cell> moves;

	for (Cell& move : availableMoves) {
		bool isOccupied = false;

		for (Piece* friendlyPiece : activePieces) {
			if (friendlyPiece->getCol() == move.col && friendlyPiece->getRow() == move.row) {
				isOccupied = true;
				break;
			}
		}

		if (!isOccupied) {
			moves.push_back(move);
		}
	}

	availableMoves = moves;
}

bool Chess::putPiece() {
	if (!targetCell.isEmpty) {
		for (Cell& move : availableMoves) {
			if (move.col == targetCell.col && move.row == targetCell.row) {
                lastMove.previous = selectedPiece->getCell();
                lastMove.current = targetCell;
                lastMove.rank = selectedPiece->getRank();
                lastMove.side = selectedPiece->getSide();
                movesLog.push_back(lastMove);
				selectedPiece->move(targetCell);
				return true;
			}
		}
	}

	return false;
}

void Chess::clearSelection() {
	this->selectedCell = {0, 0, true};
	this->selectedPiece = nullptr;
	this->targetCell = {0, 0, true};
	this->availableMoves.clear();
}

void Chess::switchPlayer() {
	clearSelection();
	populatePiecesMap();

	if (currentSide == Side::White) {
		currentSide = Side::Black;
		currentState = State::BLACK;
	} else {
		currentSide = Side::White;
		currentState = State::WHITE;
	}

	std::vector<Piece*> temp = activePieces;
	activePieces = passivePieces;
	passivePieces = temp;
}

void Chess::makeComputerMove() {
	std::shuffle(std::begin(activePieces), std::end(activePieces), rng);

	for (Piece* computerPiece : activePieces) {
		this->selectedPiece = computerPiece;
		availableMoves = computerPiece->calculateMoves(piecesMap);
		filterOutPawnAttackMoves();
		filterOutsideOfBoardMoves();
		filterOutExposeKingMoves();
		filterOutOccupiedCellsMoves();

		if (availableMoves.size() > 0) {
			size_t randomIdx = (static_cast<unsigned long>(rand()) % availableMoves.size());
            Cell computerMove = availableMoves.at(randomIdx);

            lastMove.previous.row = computerPiece->getRow();
            lastMove.previous.col = computerPiece->getCol();
            lastMove.current = computerMove;
            lastMove.rank = computerPiece->getRank();
            lastMove.side = computerPiece->getSide();

			computerPiece->move(computerMove);
            movesLog.push_back(lastMove);
			currentState = State::CALCULATE_CAPTURES;
			return;
		}
	}

	currentState = State::CHECKMATE;
	winner = Side::White;
}

void Chess::calculateCaptures() {
	std::vector<Piece*> newOpponentPieces;

	for (Piece* opponentPiece : passivePieces) {
		bool thereWasEnPassantMove = selectedPiece->getRank() == Rank::PAWN && opponentPiece->getRank() == Rank::PAWN &&
				selectedPiece->getCol() == opponentPiece->getCol() &&
				selectedPiece->getRow() + (selectedPiece->getSide() == Side::White ? 1 : -1) == opponentPiece->getRow();
		if ((opponentPiece->getCol() != selectedPiece->getCol() || opponentPiece->getRow() != selectedPiece->getRow()) && !thereWasEnPassantMove) {
			newOpponentPieces.push_back(opponentPiece);
		}
	}

	passivePieces = newOpponentPieces;
}

void Chess::deinit() {
    activePieces.clear();
    passivePieces.clear();
    availableMoves.clear();
    currentSide = Side::White;
    currentState = State::WELCOME_SCREEN;
    inCheck = false;
    winner = Side::NA;
    isDraw = false;
    piecesMap.clear();
    movesLog.clear();
    lastMove = {};
}

void Chess::createClock() {
    SDL_Color fontColor = {
            .r =  255,
            .g =  0,
            .b =  0,
            .a = 255
    };

    std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
    std::chrono::seconds diff = std::chrono::duration_cast<std::chrono::seconds>(now - clockStartTime);
    int64_t secondsLeft = turnDuration - diff.count();

    if (secondsLeft == 0) {
        switchPlayer();
        return;
    }

    auto* clockTexture = new Texture(*renderer, font, std::to_string(secondsLeft), fontColor);
    clock = new Image(*clockTexture);
    clock->put(660, 200);
}

// Works only for player move, not computer move
bool Chess::performCastling(Piece* king, Piece* rook) {
    if (!king->getHasMoved() && !rook->getHasMoved() && !inCheck && king->getSide() == Side::White) {
        bool areTherePiecesBetweenKingAndRook = false;
        bool isKingSide = false;

        if (rook->getCol() > king->getCol()) {
            areTherePiecesBetweenKingAndRook = getPieceOnCell({king->getCol() + 1, king->getRow()}) != nullptr ||
                    getPieceOnCell({king->getCol() + 2, king->getRow()}) != nullptr;
            isKingSide = true;
        } else if (rook->getCol() < king->getCol()) {
            areTherePiecesBetweenKingAndRook = getPieceOnCell({king->getCol() - 1, king->getRow()}) != nullptr ||
                                               getPieceOnCell({king->getCol() - 2, king->getRow()}) != nullptr ||
                                                getPieceOnCell({king->getCol() - 3, king->getRow()}) != nullptr;
        }

        if (areTherePiecesBetweenKingAndRook) {
            return false;
        }

        // move the pieces
        if (isKingSide) {
            king->move({king->getCol() + 2, king->getRow()});
            rook->move({rook->getCol() - 2, rook->getRow()});
        } else {
            king->move({king->getCol() - 2, king->getRow()});
            rook->move({rook->getCol() + 3, rook->getRow()});
        }

        return true;
    }

    return false;
}

void Chess::showLastTenMoves() {
    for (Image* img : logImages) {
        delete img;
    }

    logImages.clear();
    int32_t yOffset = 0;
    for (int64_t moveIdx = (int64_t)movesLog.size() - 1; moveIdx >= 0; moveIdx--) {
        Move currentMove = movesLog.at((size_t)moveIdx);
        std::string line = std::string(currentMove.side == Side::White ? "White" : "Black") + std::string(" moved piece ") + rankEnumToStringMap[currentMove.rank] +
                std::string(" from ") + colToLetterMap[currentMove.previous.col] + " " + std::to_string(currentMove.previous.row + 1) +
                std::string(" to ") + colToLetterMap[currentMove.current.col] + " " + std::to_string(currentMove.current.row + 1);

        SDL_Color fontColor = {
                .r =  0,
                .g =  255,
                .b =  0,
                .a = 255
        };

        auto* logTexture = new Texture(*renderer, font, line, fontColor);
        Image* texture = new Image(*logTexture);
        texture->put(100, 660 + yOffset);
        logImages.push_back(texture);
        yOffset += 28;
    }
}

std::string pieceToString(Piece* p) {
    return std::to_string(p->getSide()) + std::to_string(p->getRank()) + std::to_string(p->getCol()) + std::to_string(p->getRow());
}

void Chess::saveGame() {
    std::string gameState;
    std::vector<Piece*> allPieces = activePieces;

    allPieces.insert(allPieces.end(), passivePieces.begin(), passivePieces.end());

    for (Piece* p : allPieces) {
        gameState += pieceToString(p);
        gameState += "\n";
    }

    gameState += "-\n";

    gameState += std::to_string(currentSide);
    gameState += "\n";

    std::ofstream out("saved-game.txt");
    out << gameState;
    out.close();
}

void Chess::loadGame() {
    std::ifstream infile("saved-game.txt");
    std::string line;

    while (std::getline(infile, line) && line != "-") {
        Side side = (Side)(int32_t)line[0];
        Rank rank = (Rank)(int32_t)line[1];
        int32_t col = (int32_t)line[2];
        int32_t row = (int32_t)line[3];

        if (side == Side::White) {
            activePieces.push_back(new )
        }
    }
}
