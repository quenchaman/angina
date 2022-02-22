#include "Test.h"

#include "engine/widget/Widget.h"
#include "config/Config.h"
#include "resources/Resources.h"
#include "engine/factory/GraphicsFactory.h"
#include "renderer/primitives/Color.h"
#include "renderer/primitives/Text.h"

Test::Test() : Engine(Config::GAME_TITLE, Config::WINDOW_DIM) {

}

Test::~Test() {

}

void Test::init() {
	Point widgetOrigin = { 100, 100 };
	rootScreen = new Widget(widgetOrigin);
	Point p = { 0, 0 };
	Dimensions dim = { 500, 100 };
	text = getFactory().createText("Hello World!", *defaultFont, p, dim);

	Widget* innerWidget = new Widget(Point{100, 200});
	Text* anotherText = getFactory().createText("I am inside", *defaultFont, p, dim);

	innerWidget->put(2, *anotherText);

	rootScreen->addChild(*innerWidget);

	rootScreen->put(1, *text);
}

void Test::update() {
}

void Test::handleLeftMouseClick([[maybe_unused]]Point point) {

}

void Test::handleBtnClick([[maybe_unused]]int32_t idx) {

}
