//
// Created by ubuntu on 12/4/21.
//

#ifndef ANGINA_BUTTON_H
#define ANGINA_BUTTON_H

#include <cstdlib>

#include "sdl/engine/object/Object.h"

struct Texture;
struct Point;
struct Rect;
struct InputEvent;
struct Renderer;

class Button : public Object {
public:
    Button(const Texture& texture, const Rect& rect);
};


#endif //ANGINA_BUTTON_H
