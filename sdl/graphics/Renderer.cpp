/*
 * Renderer.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */


#include "Renderer.h"

Renderer::Renderer(SDL_Renderer* _renderer) {
	this->renderer = _renderer;
}

void Renderer::clearRenderer() {
	SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );

}

SDL_Renderer* Renderer::getRenderer() {
	return this->renderer;
}

void Renderer::render(Texture& texture) {
	SDL_RenderCopy(this->renderer, texture.getTexture(), NULL, NULL);
}

void Renderer::updateScreen() {
	SDL_RenderPresent(this->renderer);
}
