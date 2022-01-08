/*
 * Object.h
 *
 *  Created on: Dec 27, 2021
 *      Author: ubuntu
 */

#ifndef SDL_ENGINE_OBJECT_OBJECT_H_
#define SDL_ENGINE_OBJECT_OBJECT_H_

#include <cstdint>

#include "sdl/graphics/Flip.h"
#include "sdl/primitives/Point.h"

struct Texture;
struct Rect;
struct Renderer;

class Object {
public:
	Object(Texture& t, Rect& rect, Renderer& renderer);
	~Object();

	void move(int32_t x, int32_t y);
	void draw();
	Point getPosition() const;

	Texture& texture;
	Rect& rectangle;
	double rotation = 0.0;
	Flip flip = Flip::NONE;
	Point center = Point::ZERO;
	Point position = Point::UNDEFINED;
private:
	Renderer& _renderer;
};

#endif /* SDL_ENGINE_OBJECT_OBJECT_H_ */
