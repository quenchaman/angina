/*
 * Renderer.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */


#include "Renderer.h"

#include <iostream>

#include "SDL_render.h"
#include "SDL_shape.h"

#include "sdl/graphics/Texture.h"
#include "sdl/primitives/Rect.h"
#include "sdl/components/Window.h"
#include "sdl/engine/object/Object.h"

#include "exceptions/GraphicsInitException.h"

void Renderer::clear() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

void Renderer::render(const Texture& texture) const {
	SDL_RenderCopy(renderer, texture.getTexture(), nullptr, nullptr);
}

void Renderer::render(const Rect& rect) const {
	SDL_SetRenderDrawColor(renderer, rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha);
	SDL_RenderDrawRect(renderer, &rect.rect);
}

void Renderer::render(const Object& object) const {
	const Point* center = &object.center;
	SDL_Point centerPoint = { center->x, center->y };
	SDL_RenderCopyEx(renderer, object.texture.getTexture(), nullptr, &object.rectangle.rect, object.rotation, &centerPoint, (SDL_RendererFlip) object.flip);
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
