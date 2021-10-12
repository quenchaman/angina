#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <SDL.h>

#include "sdl/resources/ImageResource.h"
#include "exceptions/ResourceLoadException.h"
#include "exceptions/GraphicsInitException.h"
#include "exceptions/WindowInitException.h"
#include "resources/Resources.h"
#include "sdl/graphics/Graphics.h"
#include "sdl/components/Window.h"

Window* window = nullptr;
SDL_Surface* globalScreenSurface = nullptr;
SDL_Surface* imageSurface = nullptr;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {

	try {
		Graphics::boot();
	} catch (const GraphicsInitException& ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}

	try {
		window = new Window("Hello, World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	} catch (const WindowInitException& ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}

	globalScreenSurface = window->getWindowSurface();

	if (globalScreenSurface == nullptr) {
		std::cerr << "SDL_GetWindowSurface failed with reason - " << SDL_GetError() << std::endl;

		return EXIT_FAILURE;
	}

	try {
		imageSurface = ImageResource::load(Resources::helloImage);
	} catch (const ResourceLoadException& e) {
		std::cerr << e << std::endl;

		return EXIT_FAILURE;
	}

	SDL_BlitSurface(imageSurface, NULL, globalScreenSurface, NULL);
	window->updateWindowSurface();
	SDL_Delay(5000);

	delete window;

	return EXIT_SUCCESS;
}
