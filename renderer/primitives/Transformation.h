#ifndef RENDERER_PRIMITIVES_TRANSFORMATION_H_
#define RENDERER_PRIMITIVES_TRANSFORMATION_H_

#include "platform/sdl/enums/Flip.h"

struct Transformation {
	double rotation = 0.0;
	Flip flip = Flip::NONE;
};

#endif /* RENDERER_PRIMITIVES_TRANSFORMATION_H_ */
