#include "Button.h"

#include "platform/sdl/primitives/Texture.h"
#include "renderer/shapes/Rect.h"

Button::Button(Texture& texture, Rect& rect): Object(texture, rect) {
}
