#include "Graphics.h"

#include <cstdint>

#include "SDL_image.h"
#include "SDL_ttf.h"

#include "exceptions/GraphicsInitException.h"

void Graphics::init() {
	boot();
	bootImageExtension();
	bootTTFExtensions();
}

void Graphics::boot() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != EXIT_SUCCESS) {
		throw GraphicsInitException(SDL_GetError());
	}
}

void Graphics::bootImageExtension() {
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		throw GraphicsInitException(SDL_GetError());
	}
}

void Graphics::bootTTFExtensions() {
	if (TTF_Init() == -1) {
		throw GraphicsInitException(SDL_GetError());
	}
}

void Graphics::shutdown() {
	IMG_Quit();
	SDL_Quit();
}

Graphics::~Graphics() {
	shutdown();
}
