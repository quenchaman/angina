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

#include "sdl/engine/buttons/ButtonManager.h"
#include "sdl/events/InputEvent.h"

struct Window;
struct Renderer;
struct Texture;
struct Rect;
struct Object;

class Engine {
public:
	Engine(std::string appTitle);
	virtual ~Engine();

	void start();
private:
	Window* window;
	SDL_Event e;
	Renderer* renderer;
	bool quit = false;

	void limitFPS(int64_t microseconds);
	void draw();
	void handleEvent();
protected:
    std::unordered_map<int32_t, Rect*> rectangles;
    std::unordered_map<int32_t, Object*> objects;
    std::unordered_map<int32_t, int32_t> visualComponentToPageIdx;
    TTF_Font* font;
    ButtonManager buttonManager;
    InputEvent event;
    int32_t page = 0;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void handleLeftMouseClick() = 0;
	virtual void handleBtnClick(int32_t idx) = 0;

	void navigateTo(int32_t page);
	void loadResources(const std::unordered_map<int32_t, std::string>& idToPaths);
	void loadText(const std::unordered_map<int32_t, std::string>& idToTexts);
	void loadButtons(const std::unordered_map<int32_t, std::string>& idToPaths, const std::unordered_map<int32_t, int32_t>& idToPageIdx);
	void addRectangle(int32_t id, Rect& rectangle);
	void addObject(int32_t id, Object& object);
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
