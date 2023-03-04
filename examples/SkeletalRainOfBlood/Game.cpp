#include "Game.h"

#include "enginev2/graphics/models/Color.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "enginev2/graphics/models/Point.h"
#include "enginev2/graphics/models/Dimensions.h"
#include "enginev2/components/ID.h"
#include "enginev2/models/GameObject.h"
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
	ID id = spriteAnimator.add(Sprite(heroFacingRight, 4, 500));
	Sprite& spr1 = spriteAnimator.get(id);
	std::shared_ptr<Sprite> sprPtr = std::make_shared<Sprite>(spr1);
	hero = objectComponent.add(GameObjectFactory::create(
		sprPtr,
		1.0f, Point(100, 100), Dimensions(64, 64)));

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
			spriteAnimator.updateSprite(hero.spritePtr->id, heroFacingRight);
			dir = DIRECTION_STATE::RIGHT;
		}
		
		spriteAnimator.activate(hero.spritePtr->id);
	}
	else if (inputComponent.key == Keyboard::KEY_A && inputComponent.touchEvent == TouchEvent::KEYBOARD_PRESS) {
		if (dir != DIRECTION_STATE::LEFT) {
			spriteAnimator.updateSprite(hero.spritePtr->id, heroFacingLeft);
			dir = DIRECTION_STATE::LEFT;
		}
		
		spriteAnimator.activate(hero.spritePtr->id);
	}
	else if (inputComponent.key == Keyboard::KEY_D && inputComponent.touchEvent == TouchEvent::KEYBOARD_RELEASE) {
		spriteAnimator.deactivate(hero.spritePtr->id);
	}
	else if (inputComponent.key == Keyboard::KEY_A && inputComponent.touchEvent == TouchEvent::KEYBOARD_RELEASE) {
		spriteAnimator.deactivate(hero.spritePtr->id);
	}
}
