/*
 * Texture.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#include "Texture.h"

#include "SDL_image.h"

Texture::Texture(SDL_Texture* _texture, int32_t _w, int32_t _h): w(_w), h(_h), texture(_texture) {}

SDL_Texture* Texture::getTexture() const {
	return texture;
}

Texture::~Texture() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

std::ostream& operator<<(std::ostream& os, const Texture& t) {
	return os << t.texture;
}
