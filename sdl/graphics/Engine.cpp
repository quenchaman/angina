/*
 * Engine.cpp
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#include "sdl/graphics/Engine.h"
#include "config/Config.h"

Engine::Engine() {
	this->window = (new Window(
		"Hello, World!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Config::SCREEN_WIDTH,
		Config::SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	));
	this->quit = false;
}

void Engine::start() {
	this->init();

	while (!this->quit) {
		while (SDL_PollEvent(&this->e) != 0) {
			if (this->e.type == SDL_QUIT) {
				this->quit = true;
			} else if (this->e.type == SDL_KEYDOWN) {
				switch (this->e.key.keysym.sym) {
					case SDLK_UP:
						this->handleUpArrowKey();
						break;
					case SDLK_DOWN:
						this->handleDownArrowKey();
						break;
					case SDLK_LEFT:
						this->handleLeftArrowKey();
						break;
					case SDLK_RIGHT:
						this->handleRightArrowKey();
						break;
					default:
						handleOtherKey();
						break;
				}
			} else {
				handleOtherKey();
			}
		}

		this->executeGameLogic();

		this->draw();
		this->window->updateWindowSurface();
	}
}
