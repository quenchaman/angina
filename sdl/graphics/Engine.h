/*
 * Engine.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_ENGINE_H_
#define SDL_GRAPHICS_ENGINE_H_

#include <vector>
#include <cstdint>
#include <string>
#include <unordered_map>

#include "SDL_ttf.h"
#include "SDL_events.h"

struct Window;
struct Renderer;
struct Texture;

class Engine {
public:
	Engine(std::string appTitle);
	virtual ~Engine();

	void start();
private:
	Window* window;
	SDL_Event e;
protected:
    Renderer* renderer;
    bool quit = false;
    std::unordered_map<int32_t, Texture*> resources;
    TTF_Font* font;

	void loadResources(const std::unordered_map<int32_t, std::string>& idToPaths);
	virtual void init() = 0;
	void draw();
	virtual void update() = 0;

	virtual void handleLeftMouseClick() = 0;
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
