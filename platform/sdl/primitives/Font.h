#ifndef PLATFORM_SDL_PRIMITIVES_FONT_H_
#define PLATFORM_SDL_PRIMITIVES_FONT_H_

#include <string>

#include "SDL_ttf.h"

class Font {
public:
	Font(const std::string& path, int32_t pointSize);
	~Font();
	TTF_Font* getFont() const;
private:
	TTF_Font* font;
};

#endif /* PLATFORM_SDL_PRIMITIVES_FONT_H_ */
