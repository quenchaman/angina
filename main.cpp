#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <SDL.h>

#include "exceptions/ResourceLoadException.h"
#include "exceptions/GraphicsInitException.h"
#include "exceptions/WindowInitException.h"
#include "resources/Resources.h"
#include "sdl/resources/ImageResource.h"
#include "sdl/graphics/Graphics.h"
#include "sdl/components/Window.h"
#include "config/Config.h"

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {
	try {
		Graphics::boot();

		Window* window = new Window(
			"Hello, World!",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			Config::SCREEN_WIDTH,
			Config::SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
		);

		Surface& imageSurface = *ImageResource::load(Resources::helloImage);

		window->getWindowSurface().paint(imageSurface);
		window->updateWindowSurface();

		SDL_Delay(5000);

		return EXIT_SUCCESS;
	} catch (const BaseException& ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}
}
