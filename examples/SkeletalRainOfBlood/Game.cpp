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
	const Dimensions paddleDimensions{ 128, 32 };
	int32_t paddleX = (width / 2) - (paddleDimensions.w / 2);
	int32_t paddleY = height - paddleDimensions.h;
	const Point paddleStartPos{ paddleX, paddleY };
	// TODO: Instead of adding a Sprite, create a SpriteRequest class.
	// That way, the loading and handling of textures will be hidden from the user.
	Sprite& spr1 = spriteAnimator.addAndGet(Sprite(loadTexture(Resources::Breakout::PADDLE)));
	GameObject o = GameObjectFactory::create(spr1, 5.0f, paddleStartPos, paddleDimensions);
	paddleId = o.id;
	objectComponent.add(o);

	// Adding the borders to prevent the paddle to go beyond bounds
	uint16_t borderThickness = 50;
	Dimensions upperAndLowerBoxDim{ width, borderThickness };
	Point upperBoxPos{ 0, -borderThickness };
	objectComponent.add(GameObjectFactory::create(upperBoxPos, upperAndLowerBoxDim));
	Point lowerBoxPos{ 0, height };
	objectComponent.add(GameObjectFactory::create(lowerBoxPos, upperAndLowerBoxDim));

	Dimensions leftAndRightBoxDim{ borderThickness, height };
	Point leftBoxPos{ -borderThickness, 0 };
	objectComponent.add(GameObjectFactory::create(leftBoxPos, leftAndRightBoxDim));

	Point rightBoxPos{ width, 0 };
	objectComponent.add(GameObjectFactory::create(rightBoxPos, leftAndRightBoxDim));

	const Dimensions ballDimensions{ 32, 32 };
	const Point ballStartingPosition{ paddleX + (paddleDimensions.w / 2), paddleY - paddleDimensions.h };
	Sprite& ballSpr = spriteAnimator.addAndGet(Sprite(loadTexture(Resources::Breakout::BALL)));
	GameObject ball = GameObjectFactory::create(ballSpr, 10.0f, ballStartingPosition, ballDimensions);
	ballId = ball.id;
	objectComponent.add(ball);
}

void Game::onUpdate()
{
}

void Game::handleEvent()
{
	if (inputComponent.isKeyPressed(Keyboard::KEY_LEFT)) {
		GameObject& paddle = objectComponent.get(paddleId);

		if (paddle.leftDirectionCollision) {
			return;
		}

		paddle.updatePosition(Point(paddle.placementPos.x - paddle.speedFactor, paddle.placementPos.y), Direction::LEFT);
	}
	else if (inputComponent.isKeyPressed(Keyboard::KEY_RIGHT)) {
		GameObject& paddle = objectComponent.get(paddleId);

		if (paddle.rightDirectionCollision) {
			return;
		}

		paddle.updatePosition(Point(paddle.placementPos.x + paddle.speedFactor, paddle.placementPos.y), Direction::RIGHT);
	}
}

void Game::handleCollisions(std::vector<std::pair<ID, ID>> collidedObjects)
{
	for (std::pair<ID, ID> collidedObjectIdsPair : collidedObjects) {
		ID collidedPaddleId = -1;

		if (collidedObjectIdsPair.first == paddleId) {
			collidedPaddleId = collidedObjectIdsPair.first;
		}

		if (collidedObjectIdsPair.second == paddleId) {
			collidedPaddleId = collidedObjectIdsPair.second;
		}

		// Our paddle has collided with something, restrict its movement.
		if (collidedPaddleId != -1) {
			GameObject& paddle = objectComponent.get(collidedPaddleId);
			paddle.rememberCollision();
		}
	}
}
