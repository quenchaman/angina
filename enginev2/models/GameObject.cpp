#include "GameObject.h"

GameObject::GameObject(ID id, Sprite& sprite, float speedFactor, Point pos, Dimensions dim):
	id(id),
	sprite(sprite),
	speedFactor(speedFactor),
	renderingPos(pos),
	placementPos(pos),
	dim(dim),
	dir(Point()),
	box(BoundingBox()),
	currentDirection(Direction::NONE),
	leftDirectionCollision(false),
	rightDirectionCollision(false)
{
	calculateBB();
}

GameObject::GameObject(ID id, Point pos, Dimensions dim):
	id(id),
	renderingPos(pos),
	placementPos(pos),
	dim(dim),
	dir(Point()),
	box(BoundingBox()),
	currentDirection(Direction::NONE),
	leftDirectionCollision(false),
	rightDirectionCollision(false)
{
	calculateBB();
}

void GameObject::updatePosition(const Point &placementPos, Direction dir)
{
	this->renderingPos = placementPos;
	this->placementPos = placementPos;
	this->currentDirection = dir;
	calculateBB();

	switch (dir)
	{
	case Direction::LEFT:
		this->rightDirectionCollision = false;
		break;
	case Direction::RIGHT:
		this->leftDirectionCollision = false;
		break;
	default:
		break;
	}
}

void GameObject::updateDirection(const Point& newDir)
{
	this->dir = newDir;
}

void GameObject::rememberCollision()
{
	switch (this->currentDirection) {
	case Direction::LEFT:
		this->leftDirectionCollision = true;
		break;
	case Direction::RIGHT:
		this->rightDirectionCollision = true;
		break;
	default:
		break;
	}
}

void GameObject::setSprite(Sprite s)
{
	this->sprite = s;
}

void GameObject::setDirection(const Point& dir)
{
	this->dir = dir;
}

void GameObject::setNormal(const Point& n)
{
	this->normal = n;
}

void GameObject::calculateBB()
{
	Point min{ this->renderingPos.x, this->renderingPos.y + this->dim.h };
	Point max{ this->renderingPos.x + this->dim.w, this->renderingPos.y };
	this->box = BoundingBox(min, max);
}

ForwardIdGenerator GameObjectFactory::idgen;
