#include "Game.h"

#include "enginev2/graphics/models/Color.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "enginev2/graphics/models/Point.h"
#include "enginev2/graphics/models/Dimensions.h"
#include "enginev2/components/ID.h"
#include "enginev2/models/GameObject.h"
#include "resources/Resources.h"

const uint32_t width = 860, height = 640;

Game::Game(): GameEngine("Skeletal Rain Of Blood", width, height), paddleId(-1), ballId(-1), paddleSpeed(0.0f)
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
	GameObject o = GameObjectFactory::create(spr1, 0.0f, paddleStartPos, paddleDimensions);
	paddleId = o.id;
	objectComponent.add(o);

	// Adding the borders to prevent the paddle to go beyond bounds
	uint16_t borderThickness = 50;
	Dimensions upperAndLowerBoxDim{ width, borderThickness };
	Point upperBoxPos{ 0, -borderThickness };
	GameObject& upperBoxObj = GameObjectFactory::create(upperBoxPos, upperAndLowerBoxDim);
	objectComponent.add(upperBoxObj);
	Point lowerBoxPos{ 0, height };
	objectComponent.add(GameObjectFactory::create(lowerBoxPos, upperAndLowerBoxDim));

	Dimensions leftAndRightBoxDim{ borderThickness, height };
	Point leftBoxPos{ -borderThickness, 0 };
	GameObject& leftBox = GameObjectFactory::create(leftBoxPos, leftAndRightBoxDim);
	objectComponent.add(leftBox);

	Point rightBoxPos{ width, 0 };
	GameObject& rightBox = GameObjectFactory::create(rightBoxPos, leftAndRightBoxDim);
	objectComponent.add(rightBox);

	const Dimensions ballDimensions{ 32, 32 };
	const Point ballStartingPosition{ paddleX + (paddleDimensions.w / 2), paddleY - paddleDimensions.h };
	Sprite& ballSpr = spriteAnimator.addAndGet(Sprite(loadTexture(Resources::Breakout::BALL)));
	GameObject ball = GameObjectFactory::create(ballSpr, 0.0f, ballStartingPosition, ballDimensions);
	ballId = ball.id;
	// the initial direction of the ball will be 45 deg. to the right
	ball.setDirection(Point{ 1, -1 });
	objectComponent.add(ball);
}

void Game::onUpdate()
{
	GameObject& ball = objectComponent.get(ballId);
	float v = ball.speedFactor;
	ball.updatePosition(Point(ball.placementPos.x + (ball.dir.x * v), ball.placementPos.y + (ball.dir.y * v)), Direction::NONE);
}

void Game::handleEvent()
{
	if (inputComponent.isKeyPressed(Keyboard::KEY_LEFT)) {
		GameObject& paddle = objectComponent.get(paddleId);

		paddle.updatePosition(Point(paddle.placementPos.x - paddle.speedFactor, paddle.placementPos.y), Direction::LEFT);
	}
	else if (inputComponent.isKeyPressed(Keyboard::KEY_RIGHT)) {
		GameObject& paddle = objectComponent.get(paddleId);

		paddle.updatePosition(Point(paddle.placementPos.x + paddle.speedFactor, paddle.placementPos.y), Direction::RIGHT);
	}
	else if (inputComponent.isKeyPressed(Keyboard::KEY_SPACE)) {
		GameObject& ball = objectComponent.get(ballId);
		ball.speedFactor = 10.0f; // Give it a push... :D
	}
}

void Game::handleCollisions(std::vector<CollisionData> collidedObjects)
{
	for (CollisionData& collidedObjectPair : collidedObjects) {
		Point newDirFirstObj = collidedObjectPair.o1.dir.reflect(collidedObjectPair.o2.dir);
	}
}
