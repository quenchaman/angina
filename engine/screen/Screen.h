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
#include <vector>

//#include "sdl/engine/buttons/ButtonManager.h"

#include "SDL_ttf.h"

struct Texture;
struct Rect;
struct Object;
struct Renderer;
struct Point;
struct Button;
struct Drawable;

/**
 * Class that represents a full screen page.
 * It is a container for objects, rectangles, etc. and provides a way to add and get these primitives for drawing.
 *
 *
 * Handles resource destruction after deinitialization.
 */
class Screen {
public:
	Screen();
	virtual ~Screen();

	void addRectangle(const int32_t id, Rect& rectangle, int32_t zIndex);
	void addObject(const int32_t id, Object& object, int32_t zIndex);
	void addButton(const int32_t id, Button& btn, int32_t zIndex);

	std::vector<Drawable*> getDrawables() const;

	//ButtonManager buttonManager;
protected:
	std::unordered_map<int32_t, Drawable*> drawables;
private:
	TTF_Font* font;
};

#endif /* SDL_ENGINE_PAGE_PAGE_H_ */
