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

//    this->pieces.push_back(new Bishop(12, 6, 7, Side::White, textures.at(9)));
//    this->pieces.push_back(new Bishop(13, 6, 7, Side::White, textures.at(9)));


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

}

