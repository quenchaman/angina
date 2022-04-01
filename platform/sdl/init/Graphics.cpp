#include "Graphics.h"

#include <cstdint>

#include "SDL_image.h"
#include "SDL_ttf.h"

#include "exceptions/GraphicsInitException.h"

namespace Graphics {
const int32_t imgFlags = IMG_INIT_PNG;

void boot() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != EXIT_SUCCESS) {
		throw GraphicsInitException(SDL_GetError());
	}
}

void bootImageExtension() {
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		throw GraphicsInitException(SDL_GetError());
	}
}

void bootTTFExtensions() {
	if (TTF_Init() == -1) {
		throw GraphicsInitException(SDL_GetError());
	}
}

void shutdown() {
	IMG_Quit();
	SDL_Quit();
}
}
