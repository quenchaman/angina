/*
 * Texture.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#include "Texture.h"

Texture::Texture(): texture(nullptr) {}

SDL_Texture* Texture::getTexture() {
	return this->texture;
}

Texture::Texture(SDL_Texture* _texture) {
	this->texture = _texture;
}

void Texture::draw(Renderer& renderer) {
	SDL_RenderCopy(renderer.getRenderer(), this->getTexture(), NULL, NULL);
}

void Texture::draw(Renderer& renderer, const SDL_Rect* destRect) {
	SDL_RenderCopy(renderer.getRenderer(), this->getTexture(), NULL, destRect);
}

Texture::~Texture() {}

void
Texture::draw(Renderer &renderer, const SDL_Rect *destRect, double angle, SDL_Point *center, SDL_RendererFlip flip) {
    SDL_Rect renderQuad = {};

    if (destRect != nullptr) {
        renderQuad.w = destRect->w;
        renderQuad.h = destRect->h;
    }

    SDL_RenderCopyEx(renderer.getRenderer(), texture, destRect, &renderQuad, angle, center, flip);
}
