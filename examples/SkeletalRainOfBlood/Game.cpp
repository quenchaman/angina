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
	heroFacingRight = loadTexture(Resources::SkeletalRainOfBlood::HERO);
	heroSpriteId = spriteAnimator.add(Sprite(Point(0, 0), heroFacingRight, 4, 500));
	heroFacingLeft = loadTexture(Resources::SkeletalRainOfBlood::HERO);
	heroFacingLeft->activateHFlip();
}

void Game::onUpdate()
{
}

void Game::handleEvent()
{
	if (inputComponent.key == Keyboard::KEY_D && inputComponent.touchEvent == TouchEvent::KEYBOARD_PRESS) {
		if (dir != DIRECTION_STATE::RIGHT) {
			spriteAnimator.updateSprite(heroSpriteId, Sprite(Point(0, 0), heroFacingRight, 4, 500));
			dir = DIRECTION_STATE::RIGHT;
		}
		
		spriteAnimator.activate(heroSpriteId);
	}
	else if (inputComponent.key == Keyboard::KEY_A && inputComponent.touchEvent == TouchEvent::KEYBOARD_PRESS) {
		if (dir != DIRECTION_STATE::LEFT) {
			spriteAnimator.updateSprite(heroSpriteId, Sprite(Point(0, 0), heroFacingLeft, 4, 500));
			dir = DIRECTION_STATE::LEFT;
		}
		
		spriteAnimator.activate(heroSpriteId);
	}
	else if (inputComponent.key == Keyboard::KEY_D && inputComponent.touchEvent == TouchEvent::KEYBOARD_RELEASE) {
		spriteAnimator.deactivate(heroSpriteId);
	}
	else if (inputComponent.key == Keyboard::KEY_A && inputComponent.touchEvent == TouchEvent::KEYBOARD_RELEASE) {
		spriteAnimator.deactivate(heroSpriteId);
	}
}
