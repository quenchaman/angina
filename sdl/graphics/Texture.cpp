/*
 * Texture.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#include "Texture.h"

SDL_Texture* Texture::fromSurface(Surface& surface, Renderer& renderer) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(
			renderer.getRenderer(),
			surface.getSurface()
	);

	if (texture == nullptr) {
		throw GraphicsInitException(SDL_GetError());
	}

	return texture;
}

SDL_Texture* Texture::getTexture() {
	return this->texture;
}


Texture::Texture(Surface& _surface, Renderer& renderer) {
	this->texture = this->fromSurface(_surface, renderer);
}
