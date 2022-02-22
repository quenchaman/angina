#include "Renderer.h"

#include <iostream>
#include <utility>

#include "SDL_render.h"
#include "SDL_shape.h"

#include "platform/sdl/primitives/Texture.h"
#include "platform/sdl/primitives/Surface.h"
#include "renderer/shapes/Rect.h"
#include "platform/sdl/components/Window.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Button.h"
#include "core/math/geometry/Geometry.h"

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

void Renderer::render(Object& object) const {
	Dimensions objectDimensions = object.getDimensions();
	Point objectPosition = object.getPosition();
	PointPair origin = std::make_pair(objectPosition.x, objectPosition.y);
	DimensionsPair dim = std::make_pair(objectDimensions.w, objectDimensions.w);
	PointPair center = Geometry::calculateCenter(origin, dim);
	SDL_Point centerPoint = { center.first, center.second };
	SDL_Rect rect = SDL_Rect{ objectPosition.x, objectPosition.y, objectDimensions.w, objectDimensions.h };

	SDL_RenderCopyEx(renderer, object.texture.getTexture(), nullptr, &rect, object.transformation.rotation, &centerPoint, (SDL_RendererFlip) object.transformation.flip);
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

	Texture* t = new Texture(texture, surface.getSurface()->w, surface.getSurface()->h);

	delete &surface;

	return t;
}

std::vector<Texture*> Renderer::from(const std::vector<Surface*>& surfaces) const {
	std::vector<Texture*> textures;

	for (Surface* surface : surfaces) {
		textures.push_back(from(*surface));
	}

	return textures;
}

Object* Renderer::from(Texture& texture, Point p, Dimensions dim) const {
	Object* object = new Object(texture, dim, p);

	return object;
}

Object* Renderer::fromSurface(Surface& surface, Point p, Dimensions dim) const {
	Texture* t = from(surface);

	return from(*t, p, dim);
}

Button* Renderer::from(Texture& texture) {
	Point p = Point::UNDEFINED;
	Dimensions dim = {texture.w, texture.h};
	Button* btn = new Button(texture, p, dim);

	return btn;
}
