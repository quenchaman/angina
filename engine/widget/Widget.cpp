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

void Widget::put(Object& drawable) {
	Point newDrawablePos = origin + drawable.getPosition();
	drawable.move(newDrawablePos.x, newDrawablePos.y);

	drawables.push_back(&drawable);
}

void Widget::put(BaseButton& btn) {
	drawables.push_back(&btn);
	btnManager.registerButton(btn);
}

void Widget::addChild(Widget& widget) {
	children.push_back(&widget);
}

std::vector<Widget*>& Widget::getChildren() {
	return children;
}

std::vector<Drawable*>& Widget::getDrawables() {
	return drawables;
}

Widget::~Widget() {
	for (Widget* child : children) {
		delete child;
	}

	for (Drawable* drawable : drawables) {
		delete drawable;
	}

	std::cout << "Widget destroyed" << std::endl;
}
