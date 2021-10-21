/*
 * SpaceKillz.cpp
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#include "sdl/graphics/Engine.h"
#include "SpaceKillz.h"
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
		Resources::press,
		Resources::up,
		Resources::down,
		Resources::left,
		Resources::right
};

SpaceKillz::SpaceKillz(): Engine() {
	this->image = nullptr;
}

void SpaceKillz::draw() {
	this->renderer.clearRenderer();
	this->renderer.render(*this->image);
	this->renderer.updateScreen();
	SDL_Delay(50);
}

void SpaceKillz::executeGameLogic() {

}

void SpaceKillz::init() {
	this->images = ImageResource::loadBulk(paths);
	this->image = &this->renderer.transformSurfaceToTexture(
			*this->images[KEY_PRESS_SURFACE_DEFAULT]
	 );
}

SpaceKillz::~SpaceKillz() {
	this->image = nullptr;
}

void SpaceKillz::handleUpArrowKey() {
	this->image = &this->renderer.transformSurfaceToTexture(*this->images[KEY_PRESS_SURFACE_UP]);
}

void SpaceKillz::handleDownArrowKey() {
	this->image = &this->renderer.transformSurfaceToTexture(*this->images[KEY_PRESS_SURFACE_DOWN]);
}

void SpaceKillz::handleLeftArrowKey() {
	this->image = &this->renderer.transformSurfaceToTexture(*this->images[KEY_PRESS_SURFACE_LEFT]);;
}

void SpaceKillz::handleRightArrowKey() {
	this->image = &this->renderer.transformSurfaceToTexture(*this->images[KEY_PRESS_SURFACE_RIGHT]);
}

void SpaceKillz::handleOtherKey() {
	this->image = &this->renderer.transformSurfaceToTexture(*this->images[KEY_PRESS_SURFACE_DEFAULT]);
}
