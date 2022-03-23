#include "Engine.h"

#include <vector>
#include <string>
#include <iostream>

#include "platform/sdl/resource-loader/ResourceLoader.h"
#include "engine/config/EngineConfig.h"
#include "platform/sdl/primitives/Texture.h"
#include "platform/sdl/primitives/Surface.h"
#include "resources/Resources.h"
#include "renderer/primitives/Color.h"
#include "renderer/shapes/Rect.h"
#include "platform/thread/ThreadUtils.h"
#include "platform/time/Time.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Button.h"
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"

Engine::Engine(std::string appTitle, Dimensions screenSize):
		window(Window(
			appTitle,
			{ SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED },
			{ screenSize.w, screenSize.h },
			SDL_WINDOW_SHOWN
    )),
		renderer(Renderer(window)),
		factory(GraphicsFactory(renderer)),
		rootScreen(nullptr),
		defaultFont(Font(Resources::montserratFont, 28)) {

    event.init();
}

void Engine::start() {
	init();
	Time time;

	while (!quit) {
		time.getElapsed();
		renderer.clear();

		while (event.poll()) {
			if (event.hasExitEvent()) {
				quit = true;
				break;
			}

			handleEvent();
		}

		update();

		draw();

		renderer.update();

		int64_t timePassed = time.getElapsed().toMicroseconds();

		ThreadUtils::sleepFor(timePassed);
	}
}

void Engine::draw() {
	if (rootScreen != nullptr) {
		draw(*rootScreen);
	}
}

void Engine::draw(Widget& widget) {
	for (auto const& drawable : widget.getDrawables()) {
		drawable->draw(renderer);
	}

	for (Widget* w : widget.getChildren()) {
		draw(*w);
	}
}

void Engine::limitFPS(int64_t elapsedTime) {
	const int64_t maxFrames = EngineConfig::FRAME_RATE;
	const int64_t timeForFrameMicro = 1000000 / maxFrames;
	const int64_t sleepTime = timeForFrameMicro - elapsedTime;

	if (sleepTime <= 0) {
		return;
	}

	ThreadUtils::sleepFor(sleepTime);
}

void Engine::handleEvent() {
	if (event.type == EventType::MOUSE_RELEASE) {
		if (!btnManager.invokeCallback(event)) {
			handleLeftMouseClick(Point{event.posX, event.posY});
		}
	}
}

GraphicsFactory& Engine::getFactory() {
	return factory;
}

void Engine::clearScreen() {
	if (rootScreen != nullptr) {
		delete rootScreen;
		rootScreen = nullptr;
	}
}

void Engine::changeScreen(Widget& widget) {
	clearScreen();

	rootScreen = &widget;
}

Engine::~Engine() {
	clearScreen();
	event.deinit();

	std::cout << "Engine destroyed" << std::endl;
}
