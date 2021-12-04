/*
 * Engine.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_ENGINE_H_
#define SDL_GRAPHICS_ENGINE_H_

#include <vector>
#include <string>
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

#include "sdl/components/Window.h"
#include "config/Globals.h"
#include "sdl/graphics/Graphics.h"
#include "sdl/graphics/Renderer.h"
#include "sdl/graphics/Image.h"
#include "sdl/resources/ImageResource.h"
#include "sdl/components/Transformer.h"

class Engine {
public:
	Engine(std::string appTitle);
	virtual ~Engine();

	void start();
	void loadGameResources(std::vector<std::string> paths);
	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void executeGameLogic() = 0;

	virtual void handleUpArrowKey() = 0;
	virtual void handleDownArrowKey() = 0;
	virtual void handleLeftArrowKey() = 0;
	virtual void handleRightArrowKey() = 0;
	virtual void handleOtherKey() = 0;
	virtual void handleLeftMouseClick() = 0;
private:
	Window* window;
	SDL_Event e;
protected:
    Renderer* renderer;
    bool quit;
    std::map<std::string, Image*> resources;
private:
    void executeDraw();
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
