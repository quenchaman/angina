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
    draw(renderer, destRect, 0.0, SDL_RendererFlip::SDL_FLIP_NONE);
}

void Texture::draw(Renderer &renderer, const SDL_Rect *destRect, double angle) {
    draw(renderer, destRect, angle, SDL_RendererFlip::SDL_FLIP_NONE);
}


Texture::~Texture() {
    std::cout << "Texture destroyed" << std::endl;
    SDL_DestroyTexture(texture);
}

void
Texture::draw(Renderer &renderer, const SDL_Rect* destRect, double angle, SDL_RendererFlip flip) {
    SDL_Point point = { destRect->w / 2, destRect->h / 2 };

    SDL_RenderCopyEx(renderer.getRenderer(), texture, NULL, destRect, angle, &point, flip);
}

SDL_Point Texture::getSize() {
    SDL_Point point;
    SDL_QueryTexture(texture, NULL, NULL, &point.x, &point.y);
    return point;
}

Texture::Texture(Renderer& renderer, TTF_Font* font, std::string textureText, SDL_Color color) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), textSurface);

    SDL_FreeSurface(textSurface);
}

