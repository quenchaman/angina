#include "Test.h"

#include "config/Config.h"
#include "engine/screen/Screen.h"
#include "resources/Resources.h"
#include "sdl/engine/factory/GraphicsFactory.h"
#include "renderer/primitives/Color.h"

Test::Test() : Engine(Config::GAME_TITLE, Config::WINDOW_DIM) {

}

Test::~Test() {

}

void Test::init() {
	screen = new Screen();
	Rect r = Rect(0, 0, 400, 400, Color::NONE);
	Object& obj = *getFactory().createObject(Resources::startScreen, r);

	screen->addObject(0, obj, 0);
}

void Test::update() {

}

void Test::handleLeftMouseClick([[maybe_unused]]Point point) {

}

void Test::handleBtnClick([[maybe_unused]]int32_t idx) {

}
