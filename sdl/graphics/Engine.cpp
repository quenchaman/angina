/*
 * Engine.cpp
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#include "Engine.h"

Engine::Engine(std::string appTitle): quit(false) {
    Graphics::boot();
    Graphics::bootImageExtension();
    window = new Window(
            appTitle,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            Globals::config.screenWidth,
            Globals::config.screenHeight,
            SDL_WINDOW_SHOWN
    );
    renderer = &Graphics::bootRenderer(this->window->getWindow());
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

		this->executeDraw();
		this->window->updateWindowSurface();
	}
}

void Engine::loadGameResources(std::vector<std::string> paths) {
	std::vector<Surface*> surfaces = ImageResource::loadBulk(paths);
	std::vector<Texture*> textures = Transformer::transformSurfacesToTextures(this->renderer, surfaces);

    int32_t idx = 0;

    for (Texture* texture : textures) {
        SDL_Point size = texture->getSize();
        SDL_Rect rect = {
                0, 0,
                size.x, size.y
        };
        resources[paths.at((size_t)idx)] = new Image(*texture, rect);
        idx++;
    }
}

void Engine::executeDraw() {
    this->renderer->clearRenderer();

    this->draw();

    this->renderer->updateScreen();
    SDL_Delay(50);
}

Engine::~Engine() {
    // Clean-up resources
    for (auto const& [key, val] : resources) {
        delete val;
    }

    SDL_DestroyRenderer(renderer->getRenderer());
    SDL_DestroyWindow(window->getWindow());
    IMG_Quit();
    SDL_Quit();
}
