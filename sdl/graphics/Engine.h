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
	Engine();
	virtual ~Engine() {};

	void start();
	std::vector<Texture*> loadGameTextures(std::vector<std::string> paths);
	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void executeGameLogic() = 0;

	virtual void handleUpArrowKey() = 0;
	virtual void handleDownArrowKey() = 0;
	virtual void handleLeftArrowKey() = 0;
	virtual void handleRightArrowKey() = 0;
	virtual void handleOtherKey() = 0;
	virtual void handleLeftMouseClick() = 0;
protected:
	Window* window;
	bool quit;
	SDL_Event e;
	Renderer& renderer;
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
