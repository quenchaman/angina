/*
 * Engine.cpp
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#include "Engine.h"

#include <vector>
#include <string>
#include <iostream>

#include "SDL_image.h"

#include "sdl/resources/ResourceLoader.h"
#include "sdl/components/Window.h"
#include "config/Globals.h"
#include "sdl/graphics/Graphics.h"
#include "sdl/graphics/Renderer.h"
#include "sdl/graphics/Transformer.h"
#include "sdl/graphics/Texture.h"
#include "sdl/graphics/Surface.h"
#include "resources/Resources.h"
#include "sdl/primitives/Color.h"
#include "sdl/primitives/Rect.h"
#include "sdl/engine/thread/ThreadUtils.h"
#include "sdl/engine/time/Time.h"
#include "sdl/engine/object/Object.h"
#include "sdl/components/Button.h"
#include "sdl/engine/buttons/ButtonManager.h"
#include "sdl/engine/page/Page.h"

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
	page->draw();
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
	int32_t buttonIdx = page->buttonManager.getClickedButtonIndex(event);

	if (buttonIdx != -1) {
		handleBtnClick(buttonIdx);
	}
}

void Engine::navigateTo(Page* page) {
	clearPage();
	this->page = page;
}

void Engine::clearPage() {
	if (page != nullptr) {
		delete page;
		page = nullptr;
	}
}

Renderer* Engine::getRenderer() const {
	return renderer;
}

Engine::~Engine() {
	if (page != nullptr) {
		delete page;
		page = nullptr;
	}

	if (renderer != nullptr) {
		delete renderer;
		renderer = nullptr;
	}

	if (window != nullptr) {

	}
    delete window;

    IMG_Quit();
    SDL_Quit();

    std::cout << "Engine deinitialised" << std::endl;
}
