#include "../screen/Screen.h"

#include <iostream>

#include "renderer/primitives/Button.h"
#include "renderer/drawable/Drawable.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"
#include "renderer/shapes/Rect.h"
#include "engine/components/buttons/BaseButton.h"
#include "engine/managers/ButtonManager.h"
#include "platform/ids/ForwardIdGenerator.h"

Screen::Screen() {}

void Screen::put(Drawable& drawable) {
	drawables.push_back(&drawable);
}

const std::vector<Drawable*>& Screen::getDrawables() {
	return drawables;
}

Screen::~Screen() {
	std::cout << "Widget destroyed" << std::endl;
}
