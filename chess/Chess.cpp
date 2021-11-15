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

	this->board = new Image(*textures.at(0), boardRect);
}

void Chess::draw() {
	this->renderer.clearRenderer();

	this->board->draw(this->renderer);

	this->renderer.updateScreen();
	SDL_Delay(50);
}

void Chess::executeGameLogic() {

}
