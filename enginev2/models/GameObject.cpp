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
	resetCollisionState(dir, false);
}

void GameObject::updateDirection(const Point& newDir)
{
	this->dir = newDir;
}

void GameObject::rememberCollision()
{
	resetCollisionState(this->currentDirection, true);
}

void GameObject::setSprite(Sprite s)
{
	this->sprite = s;
}

void GameObject::calculateBB()
{
	Point min{ this->renderingPos.x, this->renderingPos.y + this->dim.h };
	Point max{ this->renderingPos.x + this->dim.w, this->renderingPos.y };
	this->box = BoundingBox(min, max);
}

void GameObject::resetCollisionState(Direction dir, bool hasCollision)
{
	switch (dir) {
	case Direction::LEFT:
		this->leftDirectionCollision = hasCollision;
		break;
	case Direction::RIGHT:
		this->rightDirectionCollision = hasCollision;
		break;
	default:
		break;
	}
}

ForwardIdGenerator GameObjectFactory::idgen;
