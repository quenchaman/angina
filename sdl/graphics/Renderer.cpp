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
#include "sdl/graphics/Surface.h"
#include "sdl/primitives/Rect.h"
#include "sdl/components/Window.h"
#include "sdl/engine/object/Object.h"
#include "sdl/components/Button.h"

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

Texture* Renderer::from(Surface& surface) const {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(
			renderer,
			surface.getSurface()
	);

	if (texture == nullptr) {
		throw GraphicsInitException(SDL_GetError());
	}

	delete &surface;

	return new Texture(texture, surface.getSurface()->w, surface.getSurface()->h);
}

std::vector<Texture*> Renderer::from(const std::vector<Surface*>& surfaces) const {
	std::vector<Texture*> textures;

	for (Surface* surface : surfaces) {
		textures.push_back(from(*surface));
	}

	return textures;
}

Object* Renderer::from(Texture& texture) const {
	Rect* rect = new Rect(Point::UNDEFINED, {texture.w, texture.h}, Color::NONE);
	Object* object = new Object(texture, *rect);

	return object;
}

Object* Renderer::fromSurface(Surface& surface) const {
	Texture* t = from(surface);

	return from(*t);
}

Button* Renderer::from(const Texture& texture) {
	Rect* rect = new Rect(Point::UNDEFINED, {texture.w, texture.h}, Color::NONE);
	Button* btn = new Button(texture, *rect);

	return btn;
}
