#include "LinearFixedMovementManager.h"

LinearFixedMovementManager::LinearFixedMovementManager() {}

void LinearFixedMovementManager::addMoveable(MovingObject& moveable) {
	moveables.push_back(&moveable);
}

void LinearFixedMovementManager::processFrame(int64_t elapsedTime) {
	for (MovingObject* moveable : moveables) {
		processMoveable(*moveable, elapsedTime);
	}
}

void LinearFixedMovementManager::processMoveable(MovingObject& moveable, int64_t elapsedTimeMicro) {
	int32_t unitsTravelled = static_cast<int32_t>((moveable.getVelocity() * elapsedTimeMicro) / 1000000);
	Point currentPos = moveable.getPosition();
	Point destination = moveable.getDestination();

	// Here I try to do linear interpolation
	int32_t x = currentPos.x + unitsTravelled;

	int32_t y = (currentPos.y * (destination.x - x) + destination.y * (x - currentPos.x)) / (destination.x - currentPos.x);

	moveable.move(x, y);
}
