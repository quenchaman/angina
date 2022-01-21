/*
 * Page.cpp
 *
 *  Created on: Jan 2, 2022
 *      Author: ubuntu
 */

#include "Page.h"

#include "sdl/graphics/Transformer.h"
#include "sdl/graphics/Renderer.h"
#include "sdl/resources/ResourceLoader.h"
#include "resources/Resources.h"
#include "sdl/primitives/Color.h"
#include "sdl/graphics/Texture.h"
#include "sdl/primitives/Rect.h"
#include "sdl/engine/object/Object.h"
#include "sdl/components/Button.h"
#include "sdl/primitives/Point.h"

Page::Page(Renderer& renderer): _renderer(renderer) {
	font = ResourceLoader::loadFont(Resources::montserratFont, 28);
}

Page::~Page() {
	for (auto const& [id, rectangle] : rectangles) {
		delete rectangle;
	}

	for (auto const& [id, object] : objects) {
		delete object;
	}
}

void Page::addRectangle(int32_t id, Rect& rectangle) {
	rectangles[id] = &rectangle;
}

void Page::addObject(int32_t id, Object& object) {
	objects[id] = &object;
}

void Page::addObject(int32_t id, const std::string& resourcePath, Point position) {
	Surface* surface = ResourceLoader::load(resourcePath);
	Texture* texture = Transformer::transformSurfaceToTexture(_renderer, *surface);

	objects[id] = Transformer::transformTextureToObject(_renderer, *texture);
	objects[id]->move(position.x, position.y);
}

void Page::addButton(int32_t id, const std::string& resourcePath, Point position) {
	Surface* surface = ResourceLoader::load(resourcePath);
	Texture* texture = Transformer::transformSurfaceToTexture(_renderer, *surface);

	buttonManager.registerButton(id, *texture, _renderer);
	buttonManager.getButton(id).move(position.x, position.y);
}

void Page::addText(int32_t id, std::string& text) {
	Surface* surface = ResourceLoader::loadText(font, text, Color::RED);
	Texture* texture = Transformer::transformSurfaceToTexture(_renderer, *surface);

	objects[id] = Transformer::transformTextureToObject(_renderer, *texture);
}

void Page::setBackground(Texture& background) {
	_background = &background;
}

