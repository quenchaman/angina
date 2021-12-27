/*
 * ImageResource.h
 *
 *  Created on: Oct 9, 2021
 *      Author: valeri
 */

#ifndef SDL_IMAGERESOURCE_H_
#define SDL_IMAGERESOURCE_H_

#include <string>
#include <cstdint>
#include <vector>

#include "SDL_ttf.h"

struct Surface;

namespace ResourceLoader {
	Surface* load(const std::string& path);

	std::vector<Surface*> loadBulk(const std::vector<std::string>& paths);

	TTF_Font* loadFont(const std::string& path, int32_t pointSize);
}

#endif /* SDL_IMAGERESOURCE_H_ */
