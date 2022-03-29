#ifndef PLATFORM_SDL_PRIMITIVES_FONT_H_
#define PLATFORM_SDL_PRIMITIVES_FONT_H_

#include <string>

#include "SDL_ttf.h"

class Font {
public:
    Font(const std::string &path, int32_t pointSize);
    ~Font();

    Font(const Font&) = delete;
    Font& operator=(const Font&) = delete;
    Font(Font&&) = delete;
    Font& operator=(Font&&) = delete;

    TTF_Font* getFont() const;
    int32_t getSize() const;
private:
    TTF_Font *font;
    int32_t size;
};

#endif /* PLATFORM_SDL_PRIMITIVES_FONT_H_ */
