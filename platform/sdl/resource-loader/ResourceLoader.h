#ifndef SDL_IMAGERESOURCE_H_
#define SDL_IMAGERESOURCE_H_

#include <string>
#include <cstdint>
#include <vector>

#include "SDL_ttf.h"

struct SDL_Surface;
struct Texture;
struct Color;

/*
 * Functionality for loading resources (images, fonts, sounds) from disk.
 */
namespace ResourceLoader {
	SDL_Surface& loadImage(const std::string &path);

	TTF_Font& loadFont(const std::string &path, int32_t pointSize);

	SDL_Surface& loadText(TTF_Font*, const std::string &text, Color);
}

#endif /* SDL_IMAGERESOURCE_H_ */
