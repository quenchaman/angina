/*
 * ImageResource.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: valeri
 */
#include <stdexcept>
#include <filesystem>

#include "SDL.h"
#include "SDL_image.h"

#include "sdl/components/Surface.h"
#include "ImageResource.h"
#include "exceptions/ResourceLoadException.h"

namespace ImageResource {
	const std::string resourceFolderBasePath = "../resources/";

	Surface* load(std::string path, SDL_PixelFormat* screenFormat) {
		std::string fullPathToFile = resourceFolderBasePath + path;
		std::string fileExtension = std::filesystem::path(fullPathToFile).extension();
		SDL_Surface* image = nullptr;
		SDL_Surface* optimisedImage = nullptr;

		image = IMG_Load(fullPathToFile.c_str());

		if (image == nullptr) {
			throw ResourceLoadException(SDL_GetError());
		} else {
			optimisedImage = SDL_ConvertSurface(image, screenFormat, 0);

			if (optimisedImage == nullptr) {
				throw ResourceLoadException(SDL_GetError());
			}
		}

		SDL_FreeSurface(image);

		return new Surface(optimisedImage);
	}

	std::vector<Surface*> loadBulk(std::vector<std::string> paths, SDL_PixelFormat* screenFormat) {
		std::vector<Surface*> images;

		for (std::string path : paths) {
			images.push_back(ImageResource::load(path, screenFormat));
		}

		return images;
	}
}


