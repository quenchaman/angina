/*
 * Window.h
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#ifndef SDL_COMPONENTS_WINDOW_H_
#define SDL_COMPONENTS_WINDOW_H_

#include <string>

#include "SDL.h"

#include "Surface.h"

class Window {
public:
	Window(std::string title, int x, int y, int w, int h, SDL_WindowFlags flags);

	SDL_Window* getWindow();

	Surface* getWindowSurface();

	void updateWindowSurface();

	~Window();
private:
	SDL_Window* window;
	Surface* surface;

	void init();
};


#endif /* SDL_COMPONENTS_WINDOW_H_ */
