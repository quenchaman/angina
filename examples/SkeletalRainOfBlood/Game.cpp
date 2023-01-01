#include "Game.h"

#include "enginev2/graphics/commons/primitives/Color.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "resources/Resources.h"

Game::Game(): GameEngine("Skeletal Rain Of Blood", 860, 640)
{
}

void Game::onStart()
{
	setClearColor(Color(0, 0, 0));
	auto heroSpriteId = spriteAnimator.add(Sprite(loadTexture(Resources::SkeletalRainOfBlood::HERO), 4, 500));
	spriteAnimator.activate(heroSpriteId);
}

void Game::onUpdate()
{
}

void Game::handleEvent()
{
}
