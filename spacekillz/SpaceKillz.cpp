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
	this->imageSurface = nullptr;
}

void SpaceKillz::draw() {
	window->getWindowSurface().paint(*imageSurface);
	SDL_Delay(50);
}

void SpaceKillz::executeGameLogic() {

}

void SpaceKillz::init() {
	SDL_PixelFormat* format = window->getWindowSurface().getFormat();
	this->images = ImageResource::loadBulk(paths, format);
	this->imageSurface = this->images[KEY_PRESS_SURFACE_DEFAULT];
}

SpaceKillz::~SpaceKillz() {
	this->imageSurface = nullptr;
}

void SpaceKillz::handleUpArrowKey() {
	this->imageSurface = this->images[KEY_PRESS_SURFACE_UP];
}

void SpaceKillz::handleDownArrowKey() {
	this->imageSurface = this->images[KEY_PRESS_SURFACE_DOWN];
}

void SpaceKillz::handleLeftArrowKey() {
	this->imageSurface = this->images[KEY_PRESS_SURFACE_LEFT];
}

void SpaceKillz::handleRightArrowKey() {
	this->imageSurface = this->images[KEY_PRESS_SURFACE_RIGHT];
}

void SpaceKillz::handleOtherKey() {
	this->imageSurface = this->images[KEY_PRESS_SURFACE_DEFAULT];
}
