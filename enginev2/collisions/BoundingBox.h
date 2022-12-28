#ifndef ENGINEV2_COLLISIONS_BOUNDING_BOX_H
#define ENGINEV2_COLLISIONS_BOUNDING_BOX_H

#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"

class BoundingBox {
public:
	void add(const Rectangle&);
private:
	Point min;
	Point max;
};

#endif // !ENGINEV2_COLLISIONS_BOUNDING_BOX_H
