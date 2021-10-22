/*
 * Texture.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#include "Texture.h"

SDL_Texture* Texture::getTexture() {
	return this->texture;
}

Texture::Texture(SDL_Texture* _texture) {
	this->texture = _texture;
}
