/*
 * Renderer.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */


#include "Renderer.h"

#include <iostream>

#include "SDL_render.h"

#include "exceptions/GraphicsInitException.h"

void Renderer::clear() {
	SDL_RenderClear(renderer);
}

void Renderer::render(const Texture& texture) {
	SDL_RenderCopy(renderer, texture.getTexture(), nullptr, nullptr);
}

void Renderer::render(const Rect& rect) {
	SDL_RenderDrawRect(renderer, rect.rect);
}

void Renderer::update() {
	SDL_RenderPresent(renderer);
}

Renderer::Renderer(Window& window) {
	init(window);
}

void Renderer::init(Window& window) {
	renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	std::cout << "Renderer initialised" << std::endl;
}

void Renderer::deinit() {
	SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Renderer::getRenderer() {
	return renderer;
}
