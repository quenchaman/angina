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
	this->selectPiece(x, y);
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
	uint32_t col = x / Piece::PIECE_WIDTH;
	uint32_t row = y / Piece::PIECE_HEIGHT;

	std::cout << col << "; " << row << std::endl;
}
