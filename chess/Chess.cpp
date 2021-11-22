/*
 * Chess.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: ubuntu
 */

#include "Chess.h"

void Chess::init() {
	std::vector<Texture*> textures = loadGameTextures(paths);
	SDL_Rect boardRect = {
			0, 0, 640, 640
	};

	this->boardImage = new Image(*textures.at(0), boardRect);

	this->pieceTextures[Side::White][Rank::Pawn] = textures.at(10);
	this->pieceTextures[Side::Black][Rank::Pawn] = textures.at(4);

	for (uint32_t pawnCounter = 0; pawnCounter < 8; pawnCounter++) {
		this->pieces.push_back(new Piece(pawnCounter, pawnCounter, 6, Rank::Pawn, Side::White));

		this->pieces.push_back(new Piece(-pawnCounter, pawnCounter, 1, Rank::Pawn, Side::Black));
	}
}

void Chess::draw() {
	this->renderer.clearRenderer();

	this->boardImage->draw(this->renderer);

	this->drawFigures();

	this->renderer.updateScreen();
	SDL_Delay(50);
}

void Chess::executeGameLogic() {

}

void Chess::handleLeftMouseClick() {
	int32_t x, y;
	SDL_GetMouseState(&x, &y);

	if (selectedPiece == nullptr) {
		this->selectPiece(x, y);
		this->findPossibleMoves(this->selectedPiece);
	} else {
		int32_t col = x / Piece::PIECE_WIDTH;
		int32_t row = y / Piece::PIECE_HEIGHT;

		this->movePiece({col, row, true});
	}

}

void Chess::drawFigures() {
	for (Piece* piece : this->pieces) {
		uint32_t xOffset = piece->getCol() * Piece::PIECE_WIDTH;
		uint32_t yOffset = piece->getRow() * Piece::PIECE_HEIGHT;

		SDL_Rect pieceRect = {
				(int)xOffset, (int)yOffset, Piece::PIECE_WIDTH, Piece::PIECE_HEIGHT
		};

		if (piece->getSide() == Side::White) {
			if (piece->getRank() == Rank::Pawn) {
				Image whitePawnImg(*this->pieceTextures[Side::White][Rank::Pawn], pieceRect);

				whitePawnImg.draw(this->renderer);
			}
		} else {
			Image whitePawnImg(*this->pieceTextures[Side::Black][Rank::Pawn], pieceRect);

			whitePawnImg.draw(this->renderer);
		}
	}
}

void Chess::selectPiece(int32_t x, int32_t y) {
	int32_t col = x / Piece::PIECE_WIDTH;
	int32_t row = y / Piece::PIECE_HEIGHT;
	bool isAnyPieceSelected = false;

	for (Piece* p : this->pieces) {
		if (p->getCol() == col && p->getRow() == row) {
			selectedPiece = p;
			isAnyPieceSelected = true;
			break;
		}
	}

	if (!isAnyPieceSelected) {
		selectedPiece = nullptr;
	}
}

void Chess::findPossibleMoves(Piece* piece) {
	if (selectedPiece == nullptr) {
		return;
	}

	std::vector<Cell> moves;

	if (piece->getSide() == Side::White) {
		if (piece->getRank() == Rank::Pawn) {
			moves.push_back({piece->getCol(), piece->getRow() - 1, true});
			moves.push_back({piece->getCol(), piece->getRow() - 2, true});
		}
	}

	for (uint32_t cellIdx = 0; cellIdx < moves.size(); cellIdx++) {
		Cell move = moves.at(cellIdx);

		for (Piece* p : this->pieces) {
			if (move.col == p->getCol() && move.row == p->getRow()) {
				std::cout << "hi" << std::endl;
				moves.at(cellIdx).isAllowed = false;
			}
		}
	}

	for (Cell m : moves) {
		std::cout << "The " << m.isAllowed << " move is: " << m.col << "; " << m.row << std::endl;
	}

	for (Cell m : moves) {
		if (m.isAllowed) {
			possibleMoves.push_back(m);
		}
	}
}

void Chess::movePiece(Cell move) {
	bool isAValidMoveSelected = false;

	for (Cell m : possibleMoves) {
		if (m.col == move.col && m.row == move.row) {
			isAValidMoveSelected = true;
			break;
		}
	}

	if (!isAValidMoveSelected) {
		return;
	}

	selectedPiece->move(move.col, move.row);
	selectedPiece = nullptr;
}
