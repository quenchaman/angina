#include "MovingObject.h"

#include "platform/sdl/primitives/Texture.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Point.h"

// TODO: This should wrap a Object instead of inheriting
MovingObject::MovingObject(Texture& texture, Dimensions dim, Point currentPos, int32_t vel, Point dest):
	Object(texture, dim, currentPos), velocity(vel), destination(dest) {}

MovingObject& MovingObject::setDestination(Point dest) {
	destination = dest;

	return *this;
}

int32_t MovingObject::getVelocity() const {
	return velocity;
}

Point MovingObject::getDestination() const {
	return destination;
}
