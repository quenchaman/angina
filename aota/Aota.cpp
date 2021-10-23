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
		Resources::map,
		Resources::up,
		Resources::down,
		Resources::left,
		Resources::right
};

const SDL_Rect mapRect = {
		0, 0, 4096, 4096
	};

Aota::Aota(): Engine() {
	this->image = nullptr;
}

void Aota::draw() {

	this->renderer.clearRenderer();
//	this->renderer.render(*this->image);
	this->image->draw(this->renderer, &mapRect);
//	SDL_RenderCopy(this->renderer.getRenderer(), this->image->getTexture(), NULL, NULL);
	this->renderer.updateScreen();
	SDL_Delay(50);
}

void Aota::executeGameLogic() {

}

void Aota::init() {
	std::vector<Surface*> surfaces = ImageResource::loadBulk(paths);
	this->textures = Transformer::transformSurfacesToTextures(this->renderer, surfaces);
	this->handleOtherKey();
}

Aota::~Aota() {
	this->image = nullptr;
}

void Aota::handleUpArrowKey() {
	this->image = this->textures[KEY_PRESS_SURFACE_UP];
}

void Aota::handleDownArrowKey() {
	this->image = this->textures[KEY_PRESS_SURFACE_DOWN];
}

void Aota::handleLeftArrowKey() {
	this->image = this->textures[KEY_PRESS_SURFACE_LEFT];
}

void Aota::handleRightArrowKey() {
	this->image = this->textures[KEY_PRESS_SURFACE_RIGHT];
}

void Aota::handleOtherKey() {
	this->image = this->textures[KEY_PRESS_SURFACE_DEFAULT];
}
