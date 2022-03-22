#include "Widget.h"

#include <iostream>

#include "renderer/primitives/Button.h"
#include "renderer/drawable/Drawable.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"
#include "engine/components/buttons/BaseButton.h"
#include "engine/managers/ButtonManager.h"

Widget::Widget(ButtonManager& btnMngr): btnManager(btnMngr), origin(Point::ZERO) {
}

Widget::Widget(ButtonManager& btnMngr, Point p): btnManager(btnMngr), origin(p) {
}

int32_t Widget::put(Object& drawable) {
	Point newDrawablePos = origin + drawable.getPosition();
	drawable.move(newDrawablePos.x, newDrawablePos.y);

	int32_t id = idGen.next();
	drawables[id] = &drawable;

	return id;
}

int32_t Widget::put(BaseButton& btn) {
	int32_t id = idGen.next();
	drawables[id] = &btn;
	btnManager.registerButton(btn);

	return id;
}

void Widget::addChild(Widget& widget) {
	children.push_back(&widget);
}

std::vector<Widget*>& Widget::getChildren() {
	return children;
}

std::unordered_map<int32_t, Drawable*>& Widget::getDrawables() {
	return drawables;
}

void Widget::remove(int32_t id) {
	delete drawables[id];
	drawables.erase(id);
}

Widget::~Widget() {
	for (Widget* child : children) {
		delete child;
	}

	for (auto const& [id, drawable] : drawables) {
		delete drawable;
	}

	// TODO: For now we will delete all buttons in btn Manager.
	// If we start implementing multi-widget screens then it will be a bad idea.
	btnManager.clear();

	std::cout << "Widget destroyed" << std::endl;
}
