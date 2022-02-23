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

#include "renderer/primitives/Point.h"

struct Button;
struct Drawable;
struct Object;
struct BaseButton;

/**
 * Class that represents a full screen page.
 * It is a container for objects, rectangles, etc. and provides a way to add and get these primitives for drawing.
 *
 *
 * Handles resource destruction after deinitialization.
 */
class Widget {
public:
	// TODO: Add Buttons manager here and enable adding buttons to it.
	Widget();
	Widget(Point p);
	void addChild(Widget& widget);

	void put(const int32_t id, BaseButton& btn);
	void put(const int32_t id, Object& drawable);

	std::vector<Drawable*> getDrawables() const;
	std::vector<Widget*> getChildren() const;

	//ButtonManager buttonManager;
private:
	std::unordered_map<int32_t, Drawable*> drawables;
	std::vector<Widget*> children;
	Point origin;
};

#endif /* SDL_ENGINE_PAGE_PAGE_H_ */
