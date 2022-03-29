#include "Widget.h"

#include <iostream>

#include "renderer/primitives/Button.h"
#include "renderer/drawable/Drawable.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"
#include "renderer/shapes/Rect.h"
#include "engine/components/buttons/BaseButton.h"
#include "engine/managers/ButtonManager.h"
#include "platform/ids/ForwardIdGenerator.h"

Widget::Widget() : Widget(Point::ZERO, *(new ForwardIdGenerator())) {
}

Widget::Widget(Point p): Widget(p, *(new ForwardIdGenerator())) {

}

Widget::Widget(Point p, IdGenerator& gen) :
        origin(p), idGen(gen) {
}

int32_t Widget::put(Object &drawable) {
	Point newDrawablePos = origin + drawable.getPosition();
	drawable.move(newDrawablePos.x, newDrawablePos.y);
	int32_t id = idGen.next();
	drawables[id] = &drawable;
	ids.insert(id);

	return id;
}

int32_t Widget::put(BaseButton &btn) {
    int32_t id = idGen.next();
    drawables[id] = &btn;
    btnManager.registerButton(btn);
    ids.insert(id);

    return id;
}

int32_t Widget::put(Rect& r) {
	int32_t id = idGen.next();
	drawables[id] = &r;
	ids.insert(id);

	return id;
}

void Widget::addChild(Widget &widget) {
    children.push_back(&widget);
}

std::vector<Widget*>& Widget::getChildren() {
    return children;
}

// Don't like this very much but nothing better comes to mind.
// What needs to happen is that the drawables are returned in order of insertion.
std::vector<Drawable*> Widget::getDrawables() {
    std::vector<Drawable*> draws;

    for (int32_t n : ids) {
        draws.push_back(drawables[n]);
    }

    return draws;
}

void Widget::remove(int32_t id) {
	delete drawables[id];
	drawables.erase(id);
	ids.erase(id);
}

ButtonManager& Widget::getButtonManager() {
    return btnManager;
}

void Widget::onDestroy(std::function<void(void)> callback) {
    onDestroyCallback = callback;
}

Widget::~Widget() {
    for (Widget *child : children) {
        delete child;
    }

    for (auto const& [id, drawable] : drawables) {
        delete drawable;
    }

    std::cout << "Widget destroyed" << std::endl;
}
