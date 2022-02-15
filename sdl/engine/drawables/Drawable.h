/*
 * Drawable.h
 *
 *  Created on: Feb 15, 2022
 *      Author: Freeware Sys
 */

#ifndef SDL_ENGINE_DRAWABLES_DRAWABLE_H_
#define SDL_ENGINE_DRAWABLES_DRAWABLE_H_

#include <cstdint>

#include "sdl/graphics/Renderer.h"

template <class T>
class Drawable {
public:
	Drawable(const T& thing): it(thing), zIndex(0) {
	}

	Drawable(const T& thing, int32_t z): it(thing), zIndex(z) {
	}

	void draw(const Renderer& renderer) {
		renderer.render(it);
	}

	int32_t zIndex;
private:
	const T& it;
};

#endif /* SDL_ENGINE_DRAWABLES_DRAWABLE_H_ */
