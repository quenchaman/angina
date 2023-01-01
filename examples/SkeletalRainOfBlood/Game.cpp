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
	heroSpriteId = spriteAnimator.add(Sprite(loadTexture(Resources::SkeletalRainOfBlood::HERO), 4, 500));
}

void Game::onUpdate()
{
}

void Game::handleEvent()
{
	if (inputComponent.key == Keyboard::KEY_D && inputComponent.touchEvent == TouchEvent::KEYBOARD_PRESS) {
		spriteAnimator.activate(heroSpriteId);
	}
	else if (inputComponent.key == Keyboard::KEY_D && inputComponent.touchEvent == TouchEvent::KEYBOARD_RELEASE) {
		spriteAnimator.deactivate(heroSpriteId);
	}
}
