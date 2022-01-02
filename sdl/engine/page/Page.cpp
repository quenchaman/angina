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

	for (auto const& [id, btn] : buttonManager.getButtons()) {
		delete btn;
	}
}

void Page::addRectangle(int32_t id, Rect& rectangle) {
	rectangles[id] = &rectangle;
}

void Page::addObject(int32_t id, Object& object) {
	objects[id] = &object;
}

void Page::loadResources(const std::unordered_map<int32_t, std::string>& idToPaths) {
	for (auto const& [id, path] : idToPaths) {
		Surface* surface = ResourceLoader::load(path);
		Texture* texture = Transformer::transformSurfaceToTexture(_renderer, *surface);

		objects[id] = Transformer::transformTextureToObject(*texture);
	}
}

void Page::loadButtons(const std::unordered_map<int32_t, std::string>& idToPaths) {
	for (auto const& [id, path] : idToPaths) {
		Surface* surface = ResourceLoader::load(path);
		Texture* texture = Transformer::transformSurfaceToTexture(_renderer, *surface);

		Button* btn = Transformer::transformTextureToButton(*texture);
		buttonManager.registerButton(id, btn);
	}
}

void Page::loadText(const std::unordered_map<int32_t, std::string>& idToTexts) {
	for (auto const& [id, text] : idToTexts) {
		Surface* surface = ResourceLoader::loadText(font, text, Color::RED);
		Texture* texture = Transformer::transformSurfaceToTexture(_renderer, *surface);

		objects[id] = Transformer::transformTextureToObject(*texture);
	}
}

void Page::setBackground(Texture& background) {
	_background = &background;
}

void Page::draw() {
    for (auto const& [id, rectangle] : rectangles) {
    	_renderer.render(*rectangle);
    }

    for (auto const& [id, object] : objects) {
    	_renderer.render(*object);
	}

    for (auto const& [id, btn] : buttonManager.getButtons()) {
    	_renderer.render(*btn);
	}
}
