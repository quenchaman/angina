#include "CollisionDetector.h"

#include "enginev2/models/GameObject.h"
#include "enginev2/collisions/BoundingBox.h"

std::vector<std::pair<ID, ID>> CollisionDetector::resolveCollisions(const std::vector<GameObject>& gameObjects)
{
	std::vector<std::pair<ID, ID>> collidedObjects;

	for (const GameObject& first : gameObjects) {
		for (const GameObject& second : gameObjects) {
			if (first.id != second.id && first.box.intersects(second.box)) {
				collidedObjects.push_back(std::make_pair(first.id, second.id));
			}
		}
	}

	return collidedObjects;
}
