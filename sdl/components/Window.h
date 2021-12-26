/*
 * Window.h
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#ifndef SDL_COMPONENTS_WINDOW_H_
#define SDL_COMPONENTS_WINDOW_H_

#include <string>

#include "sdl/primitives/Point.h"
#include "sdl/primitives/Dimensions.h"

struct SDL_Window;
struct Surface;

class Window {
public:
	Window(std::string title, Point pos, Dimensions dimensions, int32_t flags);
	~Window();

	SDL_Window* getWindow();
	Surface& getSurface();
private:
	SDL_Window* window;
	Surface* surface;

	void init();
};


#endif /* SDL_COMPONENTS_WINDOW_H_ */
