#include "GameObject.h"

GameObject::GameObject(ID id, Sprite& sprite, float speedFactor, Point pos, Dimensions dim):
	id(id),
	sprite(sprite),
	speedFactor(speedFactor),
	renderingPos(pos),
	placementPos(Point(pos.x + (sprite.frameWidth / 2), pos.y + sprite.atlas->getDimensions().h)),
	dim(dim)
{}

void GameObject::updatePosition(const Point &placementPos)
{
	this->renderingPos = Point(placementPos.x - (sprite.frameWidth / 2), placementPos.y - sprite.atlas->getDimensions().h);
	this->placementPos = placementPos;
}

void GameObject::updateDirection(const Point& newDir)
{
	this->dir = newDir;
}

void GameObject::setSprite(Sprite s)
{
	this->sprite = s;
}

ForwardIdGenerator GameObjectFactory::idgen;
