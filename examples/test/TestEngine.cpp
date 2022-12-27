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
  /*const int32_t width = 960;
  const int32_t height = 860;
	Point origin = Point(width/2, 0);
	Line lr(origin, Point(0, height), Color::RED);
	Line lg(origin, Point(width, height), Color::GREEN);

	drawSerpinski(lr, lg, 1);*/

  auto sdlTex = loadTexture(Resources::Engine::sticky);
  std::shared_ptr<Texture> tex = std::make_shared<Texture>(sdlTex);
  std::vector<Rectangle> spriteFrames = {
    Rectangle(Point(0, 0), Dimensions(64, 205)),
    Rectangle(Point(64, 0), Dimensions(64, 205)),
    Rectangle(Point(128, 0), Dimensions(64, 205)),
    Rectangle(Point(196, 0), Dimensions(64, 205))
  };
  Sprite sprite(tex, spriteFrames, 400);

  auto id = spriteAnimator.add(sprite);
  spriteAnimator.activate(id);
}

void TestEngine::onUpdate()
{
  
}

void TestEngine::handleEvent() {

}
