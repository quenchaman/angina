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
#include "sdl/engine/buttons/ButtonManager.h"

Engine::Engine(std::string appTitle) {
    Graphics::boot();
    Graphics::bootImageExtension();
    Graphics::bootTTFExtensions();
    window = new Window(
            appTitle,
            { SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED },
            { Globals::config.screenWidth, Globals::config.screenHeight },
            SDL_WINDOW_SHOWN
    );
    renderer = new Renderer(*window);
    font = ResourceLoader::loadFont(Resources::montserratFont, 28);
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

void Engine::loadResources(const std::unordered_map<int32_t, std::string>& idToPaths) {
	for (auto const& [id, path] : idToPaths) {
		Surface* surface = ResourceLoader::load(path);
		Texture* texture = Transformer::transformSurfaceToTexture(*renderer, *surface);

		objects[id] = Transformer::transformTextureToObject(*texture);
	}

	std::cout << "Resources initialised" << std::endl;
}

void Engine::loadButtons(const std::unordered_map<int32_t, std::string>& idToPaths) {
	for (auto const& [id, path] : idToPaths) {
		Surface* surface = ResourceLoader::load(path);
		Texture* texture = Transformer::transformSurfaceToTexture(*renderer, *surface);

		buttonManager.registerButton(id, Transformer::transformTextureToButton(*texture));
	}
}

void Engine::loadText(const std::unordered_map<int32_t, std::string>& idToTexts) {
	for (auto const& [id, text] : idToTexts) {
		Surface* surface = ResourceLoader::loadText(font, text, Color::RED);
		Texture* texture = Transformer::transformSurfaceToTexture(*renderer, *surface);

		objects[id] = Transformer::transformTextureToObject(*texture);
	}

	std::cout << "Texts initialised" << std::endl;
}

void Engine::draw() {
    for (auto const& [id, rectangle] : rectangles) {
    	renderer->render(*rectangle);
    }

    for (auto const& [id, object] : objects) {
		renderer->render(*object);
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

void Engine::addRectangle(int32_t id, Rect& rectangle) {
	rectangles[id] = &rectangle;
}

void Engine::addObject(int32_t id, Object& object) {
	objects[id] = &object;
}

void Engine::handleEvent() {
	int32_t buttonIdx = buttonManager.getClickedButtonIndex(event);

	if (buttonIdx != -1) {
		handleBtnClick(buttonIdx);
	}
}

Engine::~Engine() {
    for (auto const& [key, val] : objects) {
        delete val;
    }

    delete renderer;
    delete window;

    IMG_Quit();
    SDL_Quit();

    std::cout << "Engine deinitialised" << std::endl;
}
