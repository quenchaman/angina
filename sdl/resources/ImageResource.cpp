/*
 * ImageResource.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: valeri
 */

#include "ImageResource.h"
#include <stdexcept>

namespace ImageResource {
	const std::string resourceFolderBasePath = "../resources/";

	SDL_Surface* loadBMP(std::string path) {
		std::string fullPathToFile = resourceFolderBasePath + path;

		SDL_Surface* imageBMP = SDL_LoadBMP(fullPathToFile.c_str());

		if (imageBMP == nullptr) {
			throw "could not load image";
		}

		return imageBMP;
	}
}
