/*
 * Renderer.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */


#include "Renderer.h"

#include <iostream>

#include "SDL_render.h"

#include "sdl/graphics/Texture.h"
#include "sdl/primitives/Rect.h"
#include "sdl/components/Window.h"
#include "sdl/engine/object/Object.h"

#include "exceptions/GraphicsInitException.h"

void Renderer::clear() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

void Renderer::render(const Texture& texture) {
	SDL_RenderCopy(renderer, texture.getTexture(), nullptr, nullptr);
}

void Renderer::render(const Rect& rect) {
	SDL_SetRenderDrawColor(renderer, rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha);
	SDL_RenderDrawRect(renderer, &rect.rect);
}

void Renderer::render(const Object& object) {
	SDL_RenderCopy(renderer, object.texture.getTexture(), nullptr, &object.rectangle.rect);
}

void Renderer::update() {
	SDL_RenderPresent(renderer);
}

Renderer::Renderer(Window& window) {
	init(window);
}

Renderer::~Renderer() {
	deinit();
}

void Renderer::init(Window& window) {
	renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED);

	std::cout << "Renderer initialised" << std::endl;
}

void Renderer::deinit() {
	SDL_DestroyRenderer(renderer);
	std::cout << "Renderer deinitialised" << std::endl;
}

SDL_Renderer* Renderer::getRenderer() {
	return renderer;
}
