/*
 * Texture.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#include "Texture.h"

#include "SDL_image.h"

Texture::Texture(SDL_Texture* _texture) {
	texture = _texture;
}

SDL_Texture* Texture::getTexture() const {
	return texture;
}

Texture::~Texture() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}
