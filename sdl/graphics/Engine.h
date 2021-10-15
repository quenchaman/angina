/*
 * Engine.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_ENGINE_H_
#define SDL_GRAPHICS_ENGINE_H_

#include "SDL.h"

#include "sdl/components/Window.h"

class Engine {
public:
	Engine();
	virtual ~Engine() {};

	void start();
	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void executeGameLogic() = 0;

	virtual void handleUpArrowKey() = 0;
	virtual void handleDownArrowKey() = 0;
	virtual void handleLeftArrowKey() = 0;
	virtual void handleRightArrowKey() = 0;
	virtual void handleOtherKey() = 0;
protected:
	Window* window;
	bool quit;
	SDL_Event e;
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
