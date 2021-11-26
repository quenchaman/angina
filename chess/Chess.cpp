/*
 * Chess.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: ubuntu
 */

#include "Chess.h"
#include "King.h"

void Chess::init() {
	std::vector<Texture*> textures = loadGameTextures(paths);
	SDL_Rect boardRect = {
			0, 0, 640, 640
	};

	this->boardImage = new Image(*textures.at(0), boardRect);

	this->pieces.reserve(32);

    for (int32_t pawnIdx = 0; pawnIdx < 8; pawnIdx++) {
        Pawn* whitePawn = new Pawn(pawnIdx + 1, pawnIdx, 6, Side::White, textures.at(10));
        this->pieces.push_back(whitePawn);

        Pawn* blackPawn = new Pawn(-pawnIdx + 1, pawnIdx, 1, Side::Black, textures.at(4));
        this->pieces.push_back(blackPawn);
    }

    this->pieces.push_back(new Knight(8, 1, 0, Side::Black, textures.at(3)));
    this->pieces.push_back(new Knight(9, 6, 0, Side::Black, textures.at(3)));

    this->pieces.push_back(new Knight(10, 1, 7, Side::White, textures.at(9)));
    this->pieces.push_back(new Knight(11, 6, 7, Side::White, textures.at(9)));

    this->pieces.push_back(new Bishop(12, 5, 7, Side::White, textures.at(7)));
    this->pieces.push_back(new Bishop(13, 2, 7, Side::White, textures.at(7)));

    this->pieces.push_back(new Bishop(14, 5, 0, Side::Black, textures.at(1)));
    this->pieces.push_back(new Bishop(15, 2, 0, Side::Black, textures.at(1)));

    this->pieces.push_back(new Rook(16, 0, 0, Side::Black, textures.at(6)));
    this->pieces.push_back(new Rook(17, 7, 0, Side::Black, textures.at(6)));

    this->pieces.push_back(new Rook(18, 0, 7, Side::White, textures.at(12)));
    this->pieces.push_back(new Rook(19, 7, 7, Side::White, textures.at(12)));

    this->pieces.push_back(new Queen(20, 3, 0, Side::Black, textures.at(5)));
    this->pieces.push_back(new Queen(21, 3, 7, Side::White, textures.at(11)));

    this->pieces.push_back(new King(22, 4, 0, Side::Black, textures.at(2)));
    this->pieces.push_back(new King(23, 4, 7, Side::White, textures.at(8)));

    if (this->state == State::INIT) {
    	this->state = State::USER;
    }
}

void Chess::draw() {
	this->renderer.clearRenderer();

	this->boardImage->draw(this->renderer);

	for (Piece* p : pieces) {
		p->draw(this->renderer);
	}

	this->renderer.updateScreen();
	SDL_Delay(50);
}

void Chess::executeGameLogic() {

}

void Chess::handleLeftMouseClick() {
	int32_t x, y;
	SDL_GetMouseState(&x, &y);

	int32_t selectedCol = x / Piece::PIECE_WIDTH;
	int32_t selectedRow = y / Piece::PIECE_HEIGHT;
	Cell cell { selectedCol, selectedRow };


	if (this->state == State::USER) {
		Piece* p = findPieceAtCell(cell);

		if (p == nullptr) {
			this->state = State::USER;
		} else {
			this->selectedPiece = p;

			this->state = State::SELECTED;
		}
	} else if (this->state == State::SELECTED) {
		this->move(this->selectedPiece, cell);

		this->state = State::USER;
	}
}

Piece* Chess::findPieceAtCell(Cell cell) {
	Piece* found = nullptr;

	for (Piece* p : this->pieces) {
		if (p->getCol() == cell.col && p->getRow() == cell.row) {
			found = p;
		}
	}

	return found;
}

void Chess::move(Piece* piece, Cell cell) {
	std::vector<Cell> allowedMoves;

	if (piece->getRank() == Rank::KNIGHT) {
		std::vector<Cell> moves;
		moves.reserve(8);

		Cell knightPosition = { piece->getCol(), piece->getRow() };

		moves.push_back({ knightPosition.col - 2, knightPosition.row - 1 });
		moves.push_back({ knightPosition.col - 1, knightPosition.row - 2 });
		moves.push_back({ knightPosition.col + 1, knightPosition.row - 2 });
		moves.push_back({ knightPosition.col + 2, knightPosition.row - 1 });
		moves.push_back({ knightPosition.col + 2, knightPosition.row + 1 });
		moves.push_back({ knightPosition.col + 1, knightPosition.row + 2 });
		moves.push_back({ knightPosition.col - 1, knightPosition.row + 2 });
		moves.push_back({ knightPosition.col - 2, knightPosition.row + 1 });

		std::vector<Cell> movesInsideBoard;

		for (Cell move : moves) {
			if (move.col >=0 && move.col <= 7 && move.row >= 0 && move.row <= 7) {
				movesInsideBoard.push_back(move);
			}
		}

		std::cout << "moves in board? " << movesInsideBoard.size() << std::endl;

		for (Cell move : movesInsideBoard) {
			bool isOnFriendlyPiece = false;

			for (Piece* p : pieces) {
				if (p->getSide() == piece->getSide() && p->getCol() == move.col && p->getRow() == move.row) {
					isOnFriendlyPiece = true;
					break;
				}
			}

			if (!isOnFriendlyPiece) {
				allowedMoves.push_back(move);
			}
		}
	}

	bool hasMadeAllowedMove = false;

	for (Cell move : allowedMoves) {
		if (move.col == cell.col && move.row == cell.row) {
			hasMadeAllowedMove = true;
			break;
		}
	}

	if (hasMadeAllowedMove) {
		piece->move(cell);
	}
}
