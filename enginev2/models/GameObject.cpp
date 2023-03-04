#include "GameObject.h"

GameObject::GameObject(ID id, std::shared_ptr<Sprite> spritePtr, float speedFactor, Point pos,
	Dimensions dim):
	id(id),
	spritePtr(spritePtr),
	speedFactor(speedFactor),
	pos(pos),
	dim(dim)
{}

ForwardIdGenerator GameObjectFactory::idgen;
