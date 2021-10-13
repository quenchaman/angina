/*
 * ImageResource.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: valeri
 */
#include <stdexcept>
#include <filesystem>

#include "sdl/components/Surface.h"
#include "ImageResource.h"
#include "exceptions/ResourceLoadException.h"

namespace ImageResource {
	const std::string resourceFolderBasePath = "../resources/";

	Surface* load(std::string path) {
		std::string fullPathToFile = resourceFolderBasePath + path;
		std::string fileExtension = std::filesystem::path(fullPathToFile).extension();
		SDL_Surface* image = nullptr;

		if (fileExtension == ".bmp") {
			image = SDL_LoadBMP(fullPathToFile.c_str());
		}

		if (image == nullptr) {
			throw ResourceLoadException(SDL_GetError());
		}

		return new Surface(image);
	}
}
