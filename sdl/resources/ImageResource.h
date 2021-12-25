/*
 * ImageResource.h
 *
 *  Created on: Oct 9, 2021
 *      Author: valeri
 */

#ifndef SDL_IMAGERESOURCE_H_
#define SDL_IMAGERESOURCE_H_

#include <string>
#include <vector>

struct Surface;

namespace ImageResource {
	Surface* load(const std::string& path);

	std::vector<Surface*> loadBulk(const std::vector<std::string>& paths);
}

#endif /* SDL_IMAGERESOURCE_H_ */
