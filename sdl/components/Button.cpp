//
// Created by ubuntu on 12/4/21.
//

#include "Button.h"

#include "sdl/engine/object/Object.h"

Button::Button(Texture& texture, Rect& rect, Renderer& renderer): Object(texture, rect, renderer) {
}

void Button::draw() {
	Object::draw();
}
