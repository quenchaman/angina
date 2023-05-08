#include "GameObject.h"

GameObject::GameObject(ID id, Sprite& sprite, float speedFactor, Point pos, Dimensions dim):
	id(id),
	sprite(sprite),
	speedFactor(speedFactor),
	pos(pos),
	dim(dim)
{}

ForwardIdGenerator GameObjectFactory::idgen;
