#include "TestEngine.h"

#include <iostream>

#include "resources/Resources.h"

#include "enginev2/graphics/commons/primitives/Line.h"

TestEngine::TestEngine(): GameEngine(), txt(nullptr) {
	GameEngine::init("Hello SDL!", 640, 480);
}

void TestEngine::onStart() {
	Point origin = Point(320, 100);
	Line lr(origin, Point(50, 400) - origin, Color::RED);
	Line lg(origin, Point(590, 400) - origin, Color::GREEN);
	Line lrlg = lr + lg;

	lineComponent.loadLine(lr);
	lineComponent.loadLine(lg);
	lineComponent.loadLine(lrlg);
}

void TestEngine::handleEvent() {

}
