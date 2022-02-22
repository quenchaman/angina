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
struct Widget;
struct GraphicsFactory;
struct Font;

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
	GraphicsFactory* factory;


	void limitFPS(int64_t microseconds);
	void draw();
	void draw(Widget& widget);
	void handleEvent();
protected:
    InputEvent event;
    Widget* rootScreen = nullptr;
    Font* defaultFont = nullptr;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void handleLeftMouseClick(Point p) = 0;
	virtual void handleBtnClick(int32_t idx) = 0;

	void navigateTo(Widget* screen);
	void clearPage();
	GraphicsFactory& getFactory() const;
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
