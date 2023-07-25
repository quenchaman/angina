#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include <utility>
#include <vector>

#include "enginev2/components/GameObjectComponent.h"
#include "enginev2/components/ID.h"

struct CollisionDetector {
	std::vector<std::pair<ID, ID>> resolveCollisions(GameObjectComponent& gameObjects);
};

#endif // !COLLISION_DETECTOR_H
