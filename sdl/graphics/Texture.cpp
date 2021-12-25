/*
 * Texture.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#include "Texture.h"

Texture::Texture(SDL_Texture* _texture) {
	this->texture = _texture;
}

SDL_Texture* Texture::getTexture() const {
	return texture;
}

Dimensions Texture::getDimensions() const {
	return dimensions;
}
