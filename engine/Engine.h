#ifndef SDL_GRAPHICS_ENGINE_H_
#define SDL_GRAPHICS_ENGINE_H_

#include <vector>
#include <cstdint>
#include <string>
#include <unordered_map>

#include "SDL_events.h"
#include "SDL_ttf.h"

#include "platform/sdl/events/InputEvent.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Point.h"

#include "engine/widget/Widget.h"
#include "platform/sdl/primitives/Font.h"
#include "engine/factory/GraphicsFactory.h"
#include "platform/sdl/components/Window.h"
#include "renderer/Renderer.h"
#include "engine/factory/GraphicsFactory.h"
#include "engine/managers/ButtonManager.h"

struct Texture;
struct Rect;
struct Object;

class Engine {
public:
	Engine(std::string appTitle, Dimensions screenSize);
	virtual ~Engine();

	void start();
private:
	Window window;
	SDL_Event e;
	Renderer renderer;
	GraphicsFactory factory;
	bool quit = false;

	void limitFPS(int64_t microseconds);
	void draw();
	void draw(Widget& widget);
	void handleEvent();
protected:
	InputEvent event;
	Widget* rootScreen;
	Font defaultFont;
	ButtonManager btnManager;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void handleLeftMouseClick(Point p) = 0;
	virtual void handleBtnClick(int32_t idx) = 0;

	void clearScreen();
	void changeScreen(Widget& widget);

	GraphicsFactory& getFactory();
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
