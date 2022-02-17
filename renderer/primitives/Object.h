/*
 * Object.h
 *
 *  Created on: Dec 27, 2021
 *      Author: ubuntu
 */

#ifndef SDL_ENGINE_OBJECT_OBJECT_H_
#define SDL_ENGINE_OBJECT_OBJECT_H_

#include <cstdint>

#include "platform/sdl/enums/Flip.h"
#include "renderer/primitives/Point.h"

struct Texture;
struct Rect;

class Object {
public:
	Object(Texture& t, Rect& rect);
	~Object();

	void move(const int32_t x, const int32_t y);
	Point getPosition() const;

	Texture& texture;
	Rect& rectangle;
	double rotation = 0.0;
	Flip flip = Flip::NONE;
	Point center = Point::ZERO;
};

#endif /* SDL_ENGINE_OBJECT_OBJECT_H_ */
