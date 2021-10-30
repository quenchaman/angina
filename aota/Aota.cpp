/*
 * SpaceKillz.cpp
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#include "Aota.h"

#include "sdl/graphics/Engine.h"
#include "sdl/resources/ImageResource.h"
#include "resources/Resources.h"
#include "sdl/graphics/Texture.h"

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT
};

std::vector<std::string> paths = {
		Resources::map
};

const SDL_Rect mapRect = {
	0, 0, 4096, 4096
};

int32_t mapMovementSpeed = 10;

Aota::Aota(): Engine() {
	this->gameImage = nullptr;
}

// TODO: I should have a data structure that will store images and their dementions and also
// their position relative to the 0,0 point.
void Aota::draw() {

	this->renderer.clearRenderer();
//	this->renderer.render(*this->image);

	this->gameImage->draw(this->renderer);

	this->renderer.updateScreen();
	SDL_Delay(50);
}

void Aota::executeGameLogic() {

}

void Aota::init() {
	std::vector<Surface*> surfaces = ImageResource::loadBulk(paths);
	std::vector<Texture*> textures = Transformer::transformSurfacesToTextures(this->renderer, surfaces);

	this->gameImages.push_back(new Image(*textures.at(0), mapRect));

	this->gameImage = this->gameImages.at(0);

	this->handleOtherKey();
}

Aota::~Aota() {
	this->gameImage = nullptr;
}

void Aota::handleUpArrowKey() {
	this->gameImage->moveDown(mapMovementSpeed);
}

void Aota::handleDownArrowKey() {
	this->gameImage->moveUp(mapMovementSpeed);
}

void Aota::handleLeftArrowKey() {
	this->gameImage->moveRight(mapMovementSpeed);
}

void Aota::handleRightArrowKey() {
	this->gameImage->moveLeft(mapMovementSpeed);
}

void Aota::handleOtherKey() {
	this->gameImage = this->gameImages[KEY_PRESS_SURFACE_DEFAULT];
}
