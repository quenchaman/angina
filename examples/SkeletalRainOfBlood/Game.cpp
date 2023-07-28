#include "Game.h"

#include "enginev2/graphics/models/Color.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "enginev2/graphics/models/Point.h"
#include "enginev2/graphics/models/Dimensions.h"
#include "enginev2/components/ID.h"
#include "enginev2/models/GameObject.h"
#include "resources/Resources.h"

const uint32_t width = 860, height = 640;

Game::Game(): GameEngine("Skeletal Rain Of Blood", width, height)
{
}

void Game::onStart()
{
	setClearColor(Color(0, 0, 0));
	const Dimensions paddleDimensions{ 64, 16 };
	const Point paddleStartPos{ (width / 2) - (paddleDimensions.w / 2), height - paddleDimensions.h };
	// TODO: Instead of adding a Sprite, create a SpriteRequest class.
	// That way, the loading and handling of textures will be hidden from the user.
	paddleTexture = loadTexture(Resources::Breakout::PADDLE);
	ID id = spriteAnimator.add(Sprite(paddleTexture, 4, 500));
	Sprite& spr1 = spriteAnimator.get(id);
	
	paddle = &objectComponent.add(GameObjectFactory::create(
		spr1,
		5.0f, paddleStartPos, paddleDimensions));
}

void Game::onUpdate()
{
}

void Game::handleEvent()
{
	if (inputComponent.isKeyPressed(Keyboard::KEY_LEFT)) {
		paddle->updatePosition(Point(paddle->placementPos.x - paddle->speedFactor, paddle->placementPos.y));
	}
	else if (inputComponent.isKeyPressed(Keyboard::KEY_RIGHT)) {
		paddle->updatePosition(Point(paddle->placementPos.x + paddle->speedFactor, paddle->placementPos.y));
	}
}
