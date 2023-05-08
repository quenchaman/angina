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
	
	GameObject& gameObj = objectComponent.add(GameObjectFactory::create(
		spr1,
		100.0f, Point(100, 100), Dimensions(64, 64)));
	hero = &gameObj;

	heroFacingLeft = loadTexture(Resources::SkeletalRainOfBlood::HERO);
	heroFacingLeft->activateHFlip();
}

void Game::onUpdate()
{
}

void Game::handleEvent()
{
	if (inputComponent.mouseButton == Mouse::RIGHT_BUTTON && inputComponent.type ==
		EventType::MOUSE_PRESS) {
		movementComponent.move(*hero, Point(inputComponent.posX, inputComponent.posY));
	}
}
