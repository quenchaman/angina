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

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "sdl/components/Window.h"
#include "config/Globals.h"
#include "sdl/graphics/Graphics.h"
#include "sdl/graphics/Renderer.h"
#include "sdl/resources/ImageResource.h"
#include "sdl/components/Transformer.h"
#include "resources/Resources.h"

Engine::Engine(std::string appTitle): quit(false) {
    Graphics::boot();
    Graphics::bootImageExtension();
    Graphics::bootTTFExtensions();
    window = new Window(
            appTitle,
            { SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED },
            { Globals::config.screenWidth, Globals::config.screenHeight }
            SDL_WINDOW_SHOWN
    );

    renderer = new Renderer(*this->window);
    font = TTF_OpenFont(("../" + Resources::montserratFont).c_str(), 28);
}

void Engine::start() {
	this->init();

	while (!this->quit) {
		while (SDL_PollEvent(&this->e) != 0) {
			if (this->e.type == SDL_QUIT) {
				this->quit = true;
			} else if (this->e.type == SDL_KEYDOWN) {
			} else if (this->e.type == SDL_MOUSEBUTTONDOWN && this->e.button.button == SDL_BUTTON_LEFT) {
				this->handleLeftMouseClick();
			} else {
			}
		}

		this->executeLogic();

		this->executeDraw();
		this->window->update();
	}
}

void Engine::loadResources(const std::unordered_map<int32_t, std::string>& idToPaths) {
	for (auto const& [id, path] : idToPaths) {
		Surface* surface = ImageResource::load(path);
		Texture* texture = Transformer::transformSurfaceToTexture(*renderer, *surface);

		resources[id] = texture;
	}
}

void Engine::executeDraw() {
    this->renderer->clear();

    this->draw();

    this->renderer->update();
    SDL_Delay(50);
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
