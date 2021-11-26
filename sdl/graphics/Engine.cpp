/*
 * Engine.cpp
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#include "Engine.h"

Engine::Engine(): window(new Window(
		"Hello, World!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Globals::config.screenWidth,
		Globals::config.screenHeight,
		SDL_WINDOW_SHOWN
	)), quit(false), renderer(Graphics::bootRenderer(this->window->getWindow())) {
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
			} else if (this->e.type == SDL_MOUSEBUTTONDOWN && this->e.button.button == SDL_BUTTON_LEFT) {
				this->handleLeftMouseClick();
			} else {
				handleOtherKey();
			}
		}

		this->executeGameLogic();

		this->draw();
		this->window->updateWindowSurface();
	}
}

std::vector<Texture*> Engine::loadGameTextures(std::vector<std::string> paths) {
	std::vector<Surface*> surfaces = ImageResource::loadBulk(paths);
	std::vector<Texture*> textures = Transformer::transformSurfacesToTextures(this->renderer, surfaces);

	return textures;
}
