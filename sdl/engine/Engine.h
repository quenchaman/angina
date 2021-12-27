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

#include "SDL_events.h"
#include "SDL_ttf.h"

struct Window;
struct Renderer;
struct Texture;
struct Rect;

class Engine {
public:
	Engine(std::string appTitle);
	virtual ~Engine();

	void start();
private:
	Window* window;
	SDL_Event e;

	void limitFPS(int64_t microseconds);
	void draw();
protected:
    Renderer* renderer;
    bool quit = false;
    std::unordered_map<int32_t, Texture*> resources;
    std::unordered_map<int32_t, const Rect*> rectangles;
    TTF_Font* font;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void handleLeftMouseClick() = 0;

	void loadResources(const std::unordered_map<int32_t, std::string>& idToPaths);
	void addRectangle(int32_t id, const Rect& rectangle);
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
