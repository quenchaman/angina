#ifndef SDL_GRAPHICS_ENGINE_H_
#define SDL_GRAPHICS_ENGINE_H_

#include <vector>
#include <cstdint>
#include <string>
#include <unordered_map>

#include "SDL_events.h"
#include "SDL_ttf.h"

#include "sdl/engine/buttons/ButtonManager.h"
#include "platform/sdl/events/InputEvent.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Point.h"

struct Window;
struct Renderer;
struct Texture;
struct Rect;
struct Object;
struct Screen;

class Engine {
public:
	Engine(std::string appTitle, Dimensions dimensions);
	virtual ~Engine();

	void start();
	Renderer* getRenderer() const;
private:
	Window* window;
	SDL_Event e;
	Renderer* renderer;
	bool quit = false;

	void limitFPS(int64_t microseconds);
	void draw();
	void handleEvent();
protected:
    InputEvent event;
    Screen* screen = nullptr;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void handleLeftMouseClick(Point p) = 0;
	virtual void handleBtnClick(int32_t idx) = 0;

	void navigateTo(Screen* screen);
	void clearPage();
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
