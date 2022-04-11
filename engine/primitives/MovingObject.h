#ifndef ENGINE_PRIMITIVES_MOVINGOBJECT_H_
#define ENGINE_PRIMITIVES_MOVINGOBJECT_H_

#include <cstdint>

#include "renderer/primitives/Object.h"

class MovingObject : public Object {
public:
	MovingObject(Texture&, Dimensions, Point currentPos, int32_t velocity, Point destination);

	MovingObject& setDestination(Point dest);
	int32_t getVelocity() const;
	Point getDestination() const;
private:
	/* pixels per second */
	int32_t velocity;
	Point destination;
};

#endif /* ENGINE_PRIMITIVES_MOVINGOBJECT_H_ */
