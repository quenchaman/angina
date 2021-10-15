/*
 * ImageResource.h
 *
 *  Created on: Oct 9, 2021
 *      Author: valeri
 */

#ifndef SDL_IMAGERESOURCE_H_
#define SDL_IMAGERESOURCE_H_

#include <cstdint>
#include <string>
#include <vector>

#include "sdl/components/Surface.h"

namespace ImageResource {
	Surface* load(std::string path);

	std::vector<Surface*> loadBulk(std::vector<std::string> paths);
}

#endif /* SDL_IMAGERESOURCE_H_ */
