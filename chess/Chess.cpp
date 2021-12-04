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
}

void Chess::draw() {
	board->draw(*renderer);

    for (Piece* piece : activePieces) {
        piece->draw(*renderer);
    }
    for (Piece* piece : passivePieces) {
        piece->draw(*renderer);
    }
}

void Chess::executeGameLogic() {
    if (currentState == State::INITIALIZE_BOARD) {
        setPiecesOnBoard();
        populatePiecesMap();
        currentState = State::WHITE;
    } else if (currentState == State::WHITE) {
        currentState = State::HUMAN;
    } else if (currentState == State::BLACK) {
        currentState = State::COMPUTER;
    } else if (currentState == State::HUMAN) {
    	if (!selectedCell.isEmpty) {
    		if (isOwnPiece(getPieceOnCell(selectedCell))) {
    			selectedPiece = getPieceOnCell(selectedCell);
    			currentState = State::AVAILABLE_MOVES;
    		}
    	}
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
    } else if (currentState == State::FILTER_OCCUPIED_CELLS_MOVES) {
    	filterOutOccupiedCellsMoves();
    	std::cout << "All the occupied cells moves for a piece are: " << availableMoves.size() << std::endl;
    	currentState = State::PUT_PIECE;
    } else if (currentState == State::SWITCH_PLAYER) {
    	switchPlayer();
    } else if (currentState == State::COMPUTER) {
    	makeComputerMove();
    } else if (currentState == State::CALCULATE_CAPTURES) {
    	calculateCaptures();
    	currentState = State::SWITCH_PLAYER;
    } else if (currentState == State::CHECKMATE) {
    	std::cout << "Player " << (winner == Side::White ? "White" : "Black") << " wins by checkmate" << std::endl;
    }
}

void Chess::handleLeftMouseClick() {
	int32_t x, y;
	SDL_GetMouseState(&x, &y);
	Cell clickedCell = {x / Piece::PIECE_WIDTH, y / Piece::PIECE_HEIGHT, false};

	if (currentState == State::HUMAN) {
		selectedCell = clickedCell;
	} else if (currentState == State::PUT_PIECE) {
		targetCell = clickedCell;
	}

}

Chess::Chess() : Engine("Chess") {
    currentState = State::INITIALIZE_BOARD;
    isWhiteHuman = true;
    currentSide = Side::White;
}

void Chess::setPiecesOnBoard() {
    for (uint32_t colIdx = 0; colIdx < (uint32_t)8; colIdx++) {
        activePieces.push_back(new Pawn(colIdx, 6, Side::White, new Image(resources[Resources::whitePawn])));
        passivePieces.push_back(new Pawn(colIdx, 1, Side::Black, new Image(resources[Resources::blackPawn])));
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

void Chess::calculateAllMoves() {

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

		Cell attackRightCell = {selectedPiece->getCol() + 1, selectedPiece->getRow() + (selectedPiece->getSide() == Side::White ? -1 : 1)};
		Piece* attackRightCellPiece = getPieceOnCell(attackRightCell);

		if (attackRightCellPiece != nullptr && attackRightCellPiece->getSide() != selectedPiece->getSide()) {
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
	std::cout << "Number of available moves " << availableMoves.size() << std::endl;
	if (!targetCell.isEmpty) {
		// Check if the target cell is in the allowed moves
		for (Cell& move : availableMoves) {
			std::cout << "col: " << move.col << "; row: " << move.row << std::endl;
			if (move.col == targetCell.col && move.row == targetCell.row) {
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
			size_t randomIdx = (rand() % availableMoves.size());

			computerPiece->move(availableMoves.at(randomIdx));
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
		if (opponentPiece->getCol() != selectedPiece->getCol() || opponentPiece->getRow() != selectedPiece->getRow()) {
			newOpponentPieces.push_back(opponentPiece);
		}
	}

	passivePieces = newOpponentPieces;
}
