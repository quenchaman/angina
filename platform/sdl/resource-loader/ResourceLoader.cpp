#include <stdexcept>
#include <string>
#include <cstdint>
#include <vector>
#include <filesystem>

#include "SDL_image.h"
#include "SDL_ttf.h"

#include "platform/sdl/primitives/Surface.h"
#include "exceptions/ResourceLoadException.h"
#include "ResourceLoader.h"
#include "renderer/primitives/Color.h"

namespace ResourceLoader {
	Surface* load(const std::string& path) {
		SDL_Surface* image = nullptr;

		image = IMG_Load(path.c_str());

		if (image == nullptr) {
			throw ResourceLoadException(SDL_GetError());
		}

		return new Surface(image);
	}

	std::vector<Surface*> loadBulk(std::vector<std::string> paths) {
		std::vector<Surface*> images;

		for (std::string path : paths) {
			images.push_back(ResourceLoader::load(path));
		}

		return images;
	}

	TTF_Font* loadFont(const std::string& path, int32_t pointSize) {
		return TTF_OpenFont(path.c_str(), pointSize);
	}

	Surface* loadText(TTF_Font* font, const std::string& text, Color color) {
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), { color.red, color.green, color.blue, color.alpha });
		return new Surface(surface);
	}
}


