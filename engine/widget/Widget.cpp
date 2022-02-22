#include "Widget.h"

#include "renderer/primitives/Button.h"
#include "renderer/drawable/Drawable.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"

Widget::Widget(): origin(Point::ZERO) {
}

Widget::Widget(Point p): origin(p) {
}

// TODO: We need a better way to generate Ids.
void Widget::put(const int32_t id, Object& drawable) {
	Point newDrawablePos = origin + drawable.getPosition();
	drawable.move(newDrawablePos.x, newDrawablePos.y);

	drawables[id] = &drawable;
}

void Widget::addButton([[maybe_unused]]const int32_t id, [[maybe_unused]]Button& btn, [[maybe_unused]]int32_t zIndex) {
	//buttonManager.registerButton(id, btn);
}

void Widget::addChild(Widget& widget) {
	children.push_back(&widget);
}

std::vector<Widget*> Widget::getChildren() const {
	return children;
}

std::vector<Drawable*> Widget::getDrawables() const {
	std::vector<Drawable*> d;

	for (auto const& [id, drawable] : drawables) {
		d.push_back(drawable);
	}

	return d;
}
