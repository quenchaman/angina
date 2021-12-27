/*
 * ImageResource.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: valeri
 */
#include <stdexcept>
#include <string>
#include <cstdint>
#include <vector>
#include <filesystem>

#include "SDL_image.h"

#include "sdl/graphics/Surface.h"
#include "exceptions/ResourceLoadException.h"
#include "ResourceLoader.h"

namespace ResourceLoader {
	Surface* load(const std::string& path) {
		std::string fileExtension = std::filesystem::path(path).extension();
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
}


