//
// Created by ubuntu on 12/4/21.
//

#ifndef ANGINA_BUTTON_H
#define ANGINA_BUTTON_H
#include <cstdlib>

#include "sdl/graphics/Image.h"
#include "sdl/primitives/Rect.h"

class Button {
public:
    Button(int32_t x, int32_t y, Image* image);
    void draw(Renderer& renderer);
    int32_t getX();
    int32_t getY();
    bool isClicked(SDL_Point p);
private:
    int32_t x{};
    int32_t y{};
    Image* image{};
    Rect* rect;
};


#endif //ANGINA_BUTTON_H
