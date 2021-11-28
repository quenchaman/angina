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

Texture::~Texture() {
    std::cout << "Texture destroyed" << std::endl;
    SDL_DestroyTexture(texture);
}

void
Texture::draw(Renderer &renderer, SDL_Rect destRect, double angle, SDL_Point center, SDL_RendererFlip flip) {
    SDL_Rect renderQuad = {};

    renderQuad.w = destRect.w;
    renderQuad.h = destRect.h;

    std::cout << "The destination rect is " << destRect.x << " ; " << destRect.y << std::endl;

    SDL_RenderCopyEx(renderer.getRenderer(), texture, &destRect, &renderQuad, angle, &center, flip);
}

SDL_Point Texture::getSize() {
    SDL_Point point;
    SDL_QueryTexture(texture, NULL, NULL, &point.x, &point.y);
    std::cout << "The rect is " << point.x << " ; " << point.y << std::endl;
    return point;
}
