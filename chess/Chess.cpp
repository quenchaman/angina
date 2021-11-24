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

	Pawn* pawn = new Pawn(1, 0, 0, Side::White, *textures.at(10));
	this->pieces.push_back(*pawn);
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

