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
#include "resources/Resources.h"
#include "sdl/engine/thread/ThreadUtils.h"
#include "sdl/engine/time/Time.h"

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
}

void Engine::start() {
	init();
	Time time;

	while (!quit) {
		time.getElapsed();

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_KEYDOWN) {
			} else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
				handleLeftMouseClick();
			} else {
			}
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

		resources[id] = texture;
	}

	std::cout << "Resources initialised" << std::endl;
}

void Engine::draw() {
    renderer->clear();

    std::cout << "Drawing textures start..." << std::endl;

    for (auto const& [id, texture] : resources) {
    	renderer->render(*texture);
    }

    std::cout << "Drawing textures end..." << std::endl;
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

Engine::~Engine() {
    for (auto const& [key, val] : resources) {
        delete val;
    }

    delete renderer;
    delete window;

    IMG_Quit();
    SDL_Quit();

    std::cout << "Engine deinitialised" << std::endl;
}
