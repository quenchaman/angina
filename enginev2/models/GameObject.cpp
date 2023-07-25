#include "GameObject.h"

GameObject::GameObject(ID id, Sprite& sprite, float speedFactor, Point pos, Dimensions dim):
	id(id),
	sprite(sprite),
	speedFactor(speedFactor),
	renderingPos(pos),
	placementPos(pos),
	dim(dim)
{
	calculateBB();
}

void GameObject::updatePosition(const Point &placementPos)
{
	this->renderingPos = placementPos;
	this->placementPos = placementPos;
	calculateBB();
}

void GameObject::updateDirection(const Point& newDir)
{
	this->dir = newDir;
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

ForwardIdGenerator GameObjectFactory::idgen;
