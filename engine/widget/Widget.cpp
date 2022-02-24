#include "Widget.h"

#include "renderer/primitives/Button.h"
#include "renderer/drawable/Drawable.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"
#include "engine/components/buttons/BaseButton.h"

Widget::Widget(): origin(Point::ZERO) {
}

Widget::Widget(Point p): origin(p) {
}

void Widget::put(Object& drawable) {
	Point newDrawablePos = origin + drawable.getPosition();
	drawable.move(newDrawablePos.x, newDrawablePos.y);

	drawables.push_back(&drawable);
}

void Widget::put(BaseButton& btn) {
	drawables.push_back(&btn);
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
