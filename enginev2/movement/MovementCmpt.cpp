#include "MovementCmpt.h"

#include "platform/time/TimeUtils.h"
#include "enginev2/models/GameObject.h"

void MovementCmpt::move(GameObject& obj, Point& destination)
{
	uint64_t now = TimeUtils::timestamp();
	Point dir{ destination.x - obj.pos.x, destination.y - obj.pos.y };
	float dist = std::sqrt(std::pow(dir.x, 2) + std::pow(dir.y, 2));
	float timeToDest = dist / obj.speedFactor;
	MovementCmd cmd{ dir, now, timeToDest };
	movingObjects[obj.id] = std::make_pair(
		&obj,
		cmd
	);
}

void MovementCmpt::update()
{
	for (auto& entry : movingObjects) {
		updatePosition(entry.second.first, entry.second.second); // Yuck...fix this at some point...
	}
}

void MovementCmpt::stop(ID id)
{
}

void MovementCmpt::updatePosition(GameObject* gameObjPtr, const MovementCmd& cmd)
{
	uint64_t now = TimeUtils::timestamp();
	float diffS = (now - cmd.startTime) / 1000.f;
	float movementScale = diffS / cmd.timeToDest;
	if (movementScale > 1) return;
	Point newPos{ static_cast<int32_t>(cmd.direction.x * movementScale),
		static_cast<int32_t>(cmd.direction.y * movementScale) };
	gameObjPtr->pos = newPos;
}
