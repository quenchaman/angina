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

#include "sdl/components/Surface.h"

namespace ImageResource {
	Surface* load(std::string path);
}

#endif /* SDL_IMAGERESOURCE_H_ */
