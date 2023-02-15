#include "Game.h"

#include "enginev2/graphics/models/Color.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "enginev2/graphics/models/Point.h"
#include "resources/Resources.h"

Game::Game(): GameEngine("Skeletal Rain Of Blood", 860, 640)
{
}

void Game::onStart()
{
	setClearColor(Color(0, 0, 0));
	// TODO: Instead of adding a Sprite, create a SpriteRequest class.
	// That way, the loading and handling of textures will be hidden from the user.
	auto heroFacingRight = loadTexture(Resources::SkeletalRainOfBlood::HERO);
	auto heroFacingLeft = loadTexture(Resources::SkeletalRainOfBlood::HERO);
	heroFacingLeft->activateHFlip();
	heroSpriteId = spriteAnimator.add(Sprite(Point(0, 0), heroFacingRight, 4, 500));
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
