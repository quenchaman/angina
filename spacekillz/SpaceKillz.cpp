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

SpaceKillz::SpaceKillz(): Engine() {
	this->imageSurface = nullptr;
}

void SpaceKillz::draw() {

}

void SpaceKillz::executeGameLogic() {
	SDL_Delay(5000);
}

void SpaceKillz::init() {
	this->imageSurface = ImageResource::load(Resources::helloImage);
	window->getWindowSurface().paint(*imageSurface);
}

SpaceKillz::~SpaceKillz() {
	this->imageSurface = nullptr;
}
