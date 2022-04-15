#include "Renderer.h"

#include <iostream>
#include <utility>

#include "SDL_render.h"
#include "SDL_shape.h"

#include "platform/sdl/primitives/Texture.h"
#include "platform/sdl/primitives/Surface.h"
#include "renderer/shapes/Rect.h"
#include "enginev2/graphics/sdl/window/Window.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Button.h"
#include "renderer/primitives/Line.h"
#include "renderer/primitives/Text.h"

#include "exceptions/GraphicsInitException.h"

void Renderer::clear() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

void Renderer::render(const Texture &texture) const {
	SDL_RenderCopy(renderer, texture.getRawTexture(), nullptr, nullptr);
}

void Renderer::render(Rect &rect) const {
	Color rectColor = rect.getColor();
	SDL_FRect rawRect = rect.getRawRect();

	SDL_SetRenderDrawColor(renderer, rectColor.red, rectColor.green,
			rectColor.blue, rectColor.alpha);
	SDL_RenderFillRectF(renderer, &rawRect);
}

void Renderer::render(Object &object) const {
	Dimensions objectDimensions = object.getDimensions();
	Point objectPosition = object.getPosition();
	SDL_FRect rect = SDL_FRect { objectPosition.x, objectPosition.y,
			objectDimensions.w, objectDimensions.h };
	Point center = object.getCenter();
	SDL_FPoint sdlCenter = { center.x, center.y };
	Transformation transform = object.getTransformation();
	Rect clip = object.getClip();
	SDL_Rect clipRect = clip.toIntRect();

	SDL_RenderCopyExF(
			renderer,
			object.getTexture().getRawTexture(),
			clip == Rect::UNDEFINED ? nullptr : &clipRect,
			&rect,
			transform.rotation,
			&sdlCenter,
			(SDL_RendererFlip) transform.flip);
}

void Renderer::render(Line& line) const {
	SDL_SetRenderDrawColor(renderer, line.color.red, line.color.green, line.color.blue, line.color.alpha);
	SDL_RenderDrawLineF(renderer, line.a.x, line.a.y, line.b.x, line.b.y);
}

void Renderer::update() {
	SDL_RenderPresent(renderer);
}

Renderer::Renderer(): renderer(nullptr) {}

void Renderer::init(Window &window) {
	renderer = SDL_CreateRenderer(window.sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	std::cout << "Renderer initialized" << std::endl;
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
	std::cout << "Renderer destroyed" << std::endl;
}
