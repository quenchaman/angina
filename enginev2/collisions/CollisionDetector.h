#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include <utility>
#include <vector>

#include "enginev2/models/GameObject.h"
#include "enginev2/components/ID.h"

struct CollisionDetector {
	std::vector<std::pair<ID, ID>> resolveCollisions(const std::vector<GameObject>& gameObjects);
};

#endif // !COLLISION_DETECTOR_H
