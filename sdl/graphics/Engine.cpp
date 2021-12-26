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


#include "sdl/components/Window.h"
#include "config/Globals.h"
#include "sdl/graphics/Graphics.h"
#include "sdl/graphics/Renderer.h"
#include "sdl/resources/ImageResource.h"
#include "sdl/components/Transformer.h"
#include "resources/Resources.h"

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
    font = TTF_OpenFont(("../" + Resources::montserratFont).c_str(), 28);
    std::cout << "Font initialized" << std::endl;
}

void Engine::start() {
	init();

	while (!quit) {
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
		SDL_Delay(50);
	}
}

void Engine::loadResources(const std::unordered_map<int32_t, std::string>& idToPaths) {
	for (auto const& [id, path] : idToPaths) {
		Surface* surface = ImageResource::load(path);
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

Engine::~Engine() {
    for (auto const& [key, val] : resources) {
        delete val;
    }

    delete renderer;
    delete window;

    IMG_Quit();
    SDL_Quit();
}
