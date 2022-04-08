#ifndef SDL_GRAPHICS_ENGINE_H_
#define SDL_GRAPHICS_ENGINE_H_

#include <vector>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <memory>

#include "SDL_events.h"
#include "SDL_ttf.h"

#include "platform/sdl/events/InputEvent.h"
#include "platform/sdl/primitives/Font.h"
#include "platform/sdl/components/Window.h"

#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Point.h"
#include "renderer/Renderer.h"

#include "engine/factory/GraphicsFactory.h"
#include "engine/managers/ButtonManager.h"

#include "platform/sdl/repositories/TextureRepository.h"
#include "platform/sdl/repositories/SurfaceRepository.h"

struct Texture;
struct Rect;
struct Object;
struct Screen;
struct Behaviour;

class Engine {
public:
	Engine(std::string appTitle, Dimensions screenSize);
	virtual ~Engine();

	void start();
private:
	Window window;
	SDL_Event e;
	Renderer renderer;
	SurfaceRepository surfaceRepo;
	TextureRepository textureRepo;
	GraphicsFactory factory;
	Screen* rootScreen;
	bool quit = false;

	void limitFPS(int64_t microseconds);
	void draw();
	void draw(Screen&);
	void handleEvent();
protected:
	InputEvent event;
	Font defaultFont;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void handleLeftMouseClick(Point) = 0;
	virtual void handleBtnClick(int32_t idx) = 0;


	void initialiseScreen();
	void addComponent(Object&);
	void cleanScreen();

	void addBehaviour(Behaviour&);

	GraphicsFactory& getFactory();
};

#endif /* SDL_GRAPHICS_ENGINE_H_ */
