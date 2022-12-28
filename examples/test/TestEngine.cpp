#include "TestEngine.h"

#include <iostream>

#include "resources/Resources.h"

#include "enginev2/graphics/commons/primitives/Line.h"
#include "enginev2/graphics/animation/Sprite.h"
#include "enginev2/graphics/sdl/primitives/Texture.h"

TestEngine::TestEngine(): txt(nullptr), maxLevels(10) {
	GameEngine::init("Hello SDL!", 960, 860);
}

void TestEngine::onStart() {
  setClearColor(Color(0, 0, 0));
  rectangleComponent.add(Rectangle(Point(100, 100), Dimensions(50, 50), Color(128, 128, 64, 255), true));
}

void TestEngine::onUpdate()
{
  
}

void TestEngine::handleEvent()
{

}
