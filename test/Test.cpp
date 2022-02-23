#include "Test.h"

#include "engine/widget/Widget.h"
#include "config/Config.h"
#include "resources/Resources.h"
#include "engine/factory/GraphicsFactory.h"
#include "renderer/primitives/Color.h"
#include "renderer/primitives/Text.h"
#include "engine/components/buttons/RectTextButton.h"

Test::Test() : Engine(Config::GAME_TITLE, Config::WINDOW_DIM) {

}

Test::~Test() {

}

void callbackFunc() {
	std::cout << "Hello ! I am the clicked button!" << std::endl;
}


void Test::init() {
	Point p = { 0, 0 };
	Dimensions dim = { 200, 70 };
	Color background = Color::BLUE;
	Color textColor = Color::RED;
	std::string txt = "Click me!";

	RectTextButton* btn = getFactory().createButton(p, dim, background, textColor, txt, *defaultFont, &callbackFunc);

	rootScreen->put(12, *btn);
}

void Test::update() {
}

void Test::handleLeftMouseClick([[maybe_unused]]Point point) {

}

void Test::handleBtnClick([[maybe_unused]]int32_t idx) {

}

