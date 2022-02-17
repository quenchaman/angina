/*
 * Page.h
 *
 *  Created on: Jan 2, 2022
 *      Author: ubuntu
 */

#ifndef SDL_ENGINE_PAGE_PAGE_H_
#define SDL_ENGINE_PAGE_PAGE_H_

#include <cstdint>
#include <unordered_map>

#include "sdl/engine/buttons/ButtonManager.h"
#include "sdl/engine/drawables/Drawable.h"

#include "SDL_ttf.h"

struct Texture;
struct Rect;
struct Object;
struct Renderer;
struct Point;
struct Button;
struct GraphicsFactory;

/**
 * Class that represents a full screen page.
 * It is a container for objects, rectangles, etc. and provides a way to add and get these primitives for drawing.
 *
 *
 * Handles resource destruction after deinitialization.
 */
class Page {
public:
	Page(Renderer& renderer);
	virtual ~Page();

	virtual void draw() = 0;

	void addRectangle(const int32_t id, const Rect& rectangle, int32_t zIndex);
	void addObject(const int32_t id, const Object& object, int32_t zIndex);
	void addButton(const int32_t id, const Button& btn, int32_t zIndex);

	ButtonManager buttonManager;
protected:
	std::unordered_map<int32_t, Drawable*> drawables;
	Renderer& _renderer;
	GraphicsFactory& graphicsFactory;
private:
	TTF_Font* font;
};

#endif /* SDL_ENGINE_PAGE_PAGE_H_ */
