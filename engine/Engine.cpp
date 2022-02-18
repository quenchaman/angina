#include "Engine.h"

#include <vector>
#include <string>
#include <iostream>

#include "SDL_image.h"

#include "sdl/resources/ResourceLoader.h"
#include "platform/sdl/components/Window.h"
#include "config/Globals.h"
#include "platform/sdl/init/Graphics.h"
#include "renderer/Renderer.h"
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
#include "sdl/engine/buttons/ButtonManager.h"
#include "engine/screen/Screen.h"
#include "sdl/engine/factory/GraphicsFactory.h"

Engine::Engine(std::string appTitle, Dimensions screenSize) {
    Graphics::boot();
    Graphics::bootImageExtension();
    Graphics::bootTTFExtensions();

    if (screenSize.h == 0 || screenSize.w == 0) {
    	screenSize = { Globals::config.screenWidth, Globals::config.screenHeight };
    }

    window = new Window(
            appTitle,
            { SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED },
            { screenSize.w, screenSize.h },
            SDL_WINDOW_SHOWN
    );
    renderer = new Renderer(*window);
    factory = new GraphicsFactory(*renderer);

    event.init();
}

void Engine::start() {
	init();
	Time time;

	while (!quit) {
		time.getElapsed();
		renderer->clear();

		while (event.poll()) {
			if (event.hasExitEvent()) {
				quit = true;
				break;
			}

			handleEvent();
		}

		update();

		draw();

		renderer->update();

		int64_t timePassed = time.getElapsed().toMicroseconds();

		ThreadUtils::sleepFor(timePassed);
	}
}

void Engine::draw() {
	for (Drawable* drawable : screen->getDrawables()) {
		drawable->draw(*renderer);
	}
}

void Engine::limitFPS(int64_t elapsedTime) {
	const int64_t maxFrames = Globals::config.frameRate;
	const int64_t timeForFrameMicro = 1000000 / maxFrames;
	const int64_t sleepTime = timeForFrameMicro - elapsedTime;

	if (sleepTime <= 0) {
		return;
	}

	ThreadUtils::sleepFor(sleepTime);
}

void Engine::handleEvent() {
	int32_t buttonIdx =0;

	if (buttonIdx != -1) {
		handleBtnClick(buttonIdx);
	} else if (event.type == EventType::MOUSE_RELEASE) {
		handleLeftMouseClick(Point{event.posX, event.posY});
	}
}

void Engine::navigateTo(Screen* screen) {
	clearPage();
	this->screen = screen;
}

void Engine::clearPage() {
	if (screen != nullptr) {
		delete screen;
		screen = nullptr;
	}
}

Renderer* Engine::getRenderer() const {
	return renderer;
}

GraphicsFactory& Engine::getFactory() const {
	return *factory;
}

Engine::~Engine() {
	clearPage();

	if (renderer != nullptr) {
		delete renderer;
		renderer = nullptr;
	}

	if (window != nullptr) {
		delete window;
		window = nullptr;
	}

    IMG_Quit();
    SDL_Quit();

    std::cout << "Engine deinitialised" << std::endl;
}
