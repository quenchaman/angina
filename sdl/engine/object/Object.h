/*
 * Object.h
 *
 *  Created on: Dec 27, 2021
 *      Author: ubuntu
 */

#ifndef SDL_ENGINE_OBJECT_OBJECT_H_
#define SDL_ENGINE_OBJECT_OBJECT_H_

struct Texture;
struct Rect;

class Object {
public:
	Object(Texture& t, Rect& rect);
	~Object();

	Texture& texture;
	Rect& rectangle;
};

#endif /* SDL_ENGINE_OBJECT_OBJECT_H_ */
