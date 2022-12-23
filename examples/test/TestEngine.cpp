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

  std::shared_ptr<Texture> tex = std::make_shared<Texture>(textureComponent.load(Resources::Engine::sticky));
  std::vector<Rectangle> spriteFrames = {
    Rectangle(Point(0, 0), Dimensions(50, 100)),
    Rectangle(Point(50, 0), Dimensions(50, 100)),
    Rectangle(Point(100, 0), Dimensions(50, 100)),
    Rectangle(Point(150, 0), Dimensions(50, 100)),
  };
  Sprite sprite(tex, spriteFrames, 500);

  auto id = spriteAnimator.add(sprite);
  spriteAnimator.activate(id);
}

void TestEngine::onUpdate()
{
  
}

void TestEngine::handleEvent() {

}

void TestEngine::drawSerpinski(const Line& lr, const Line& lg, int32_t level) {
  if (level > maxLevels) {
    return;
  }

  Line connectLrLg = lr.connect(lg);
  Line m = lr.midpoint(lg);
  Line n = connectLrLg.midpoint(lr.reversed());
  Line o = connectLrLg.reversed().midpoint(lg.reversed());

  Line om = Line(o.getEnd(), m.getEnd(), Color::BLACK);
  Line mn = Line(m.getEnd(), n.getEnd(), Color::BLACK);
  Line no = Line(n.getEnd(), o.getEnd(), Color::BLACK);

  /*lineComponent.add(lr);
  lineComponent.add(lg);
  lineComponent.add(connectLrLg);
  lineComponent.add(om);
  lineComponent.add(mn);
  lineComponent.add(no);*/

  Line co = Line(lr.getOrigin(), o.getEnd(), Color::RED);
  Line cn = Line(lr.getOrigin(), n.getEnd(), Color::RED);

  drawSerpinski(co, cn, level + 1);

  Line oa = Line(om.getOrigin(), lr.getEnd(), Color::GREEN);
  Line om1 = Line(om.getOrigin(), m.getEnd(), Color::GREEN);
  drawSerpinski(oa, om1, level + 1);

  Line nm = Line(no.getOrigin(), m.getEnd(), Color::BLUE);
  Line nb = Line(no.getOrigin(), lg.getEnd(), Color::BLUE);

  drawSerpinski(nm, nb, level + 1);
}
