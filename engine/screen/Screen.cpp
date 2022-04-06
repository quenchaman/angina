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

int32_t Screen::put(Drawable& drawable) {
	drawables[id] = &drawable;

	return id;
}

int32_t Screen::put(BaseButton &btn) {
	int32_t id = idGen.next();
	drawables[id] = &btn;
	btnManager.registerButton(btn);
	ids.insert(id);

	return id;
}

int32_t Screen::put(Rect &r) {
	int32_t id = idGen.next();
	drawables[id] = &r;
	ids.insert(id);

	return id;
}

void Screen::addChild(Screen &widget) {
	children.push_back(&widget);
}

std::vector<Screen*>& Screen::getChildren() {
	return children;
}

// Don't like this very much but nothing better comes to mind.
// What needs to happen is that the drawables are returned in order of insertion.
std::vector<Drawable*> Screen::getDrawables() {
	std::vector<Drawable*> draws;

	for (int32_t n : ids) {
		draws.push_back(drawables[n]);
	}

	return draws;
}

void Screen::remove(int32_t id) {
	delete drawables[id];
	drawables.erase(id);
	ids.erase(id);
}

ButtonManager& Screen::getButtonManager() {
	return btnManager;
}

void Screen::onDestroy(std::function<void(void)> callback) {
	onDestroyCallback = callback;
}

Screen::~Screen() {
	for (Screen *child : children) {
		delete child;
	}

	for (auto const& [id, drawable] : drawables) {
		delete drawable;
	}

	std::cout << "Widget destroyed" << std::endl;
}
