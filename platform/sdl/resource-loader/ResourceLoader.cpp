#include "ResourceLoader.h"

#include <stdexcept>
#include <string>
#include <cstdint>
#include <vector>
#include <filesystem>

#include "SDL_image.h"
#include "SDL_ttf.h"

#include "exceptions/ResourceLoadException.h"

#include "renderer/primitives/Color.h"

#include "platform/sdl/translators/Translators.h"

namespace ResourceLoader {
	// TODO: Instead of throwing an exception we should gracefully degrade with a default image.
	SDL_Surface& loadImage(const std::string &path) {
		SDL_Surface *image = IMG_Load(path.c_str());

		if (image == nullptr) {
			throw ResourceLoadException(SDL_GetError());
		}

		return *image;
	}

	TTF_Font& loadFont(const std::string &path, int32_t pointSize) {
		return *TTF_OpenFont(path.c_str(), pointSize);
	}

	SDL_Surface& loadText(TTF_Font *font, const std::string &text, Color color) {
		return *TTF_RenderText_Solid(font, text.c_str(), Translators::toSDLColor(color));
	}
}
