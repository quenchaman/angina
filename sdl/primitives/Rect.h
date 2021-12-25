/*
 * Rectangle.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_PRIMITIVES_RECT_H_
#define SDL_PRIMITIVES_RECT_H_

#include <cstdint>

#include "sdl/graphics/Drawable.h"

struct SDL_Rect;

class Rect : public Drawable {
public:
	Rect(int32_t x, int32_t y, int32_t w, int32_t h);
    Rect(SDL_Rect rect);

    void draw(Renderer& renderer);
    void draw(Renderer& renderer, const SDL_Rect* destRect);
    void draw(Renderer& renderer, const SDL_Rect* destRect, double angle);
	SDL_Rect getRaw();
    bool isInRect(SDL_Point point);
private:
	SDL_Rect _rect;
};


#endif /* SDL_PRIMITIVES_RECT_H_ */
