#include "CollisionDetector.h"

#include "enginev2/models/GameObject.h"

std::vector<std::pair<ID, ID>> CollisionDetector::resolveCollisions(GameObjectComponent& gameObjects)
{
	std::vector<std::pair<ID, ID>> collidedObjects;

	for (GameObject& first : gameObjects.data) {
		for (GameObject& second : gameObjects.data) {
			if (first.id != second.id) {
				collidedObjects.push_back(std::make_pair(first.id, second.id));
			}
		}
	}

	return collidedObjects;
}
