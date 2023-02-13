#ifndef ENGINEV2_COMPONENTS_RECTANGLECOMPONENT_H_
#define ENGINEV2_COMPONENTS_RECTANGLECOMPONENT_H_

#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "enginev2/graphics/models/Point.h"
#include "enginev2/graphics/models/Dimensions.h"

#include "enginev2/components/PrimitivesComponent.h"

class RectangleComponent : public PrimitivesComponent<Rectangle> {
public:
	RectangleComponent();

	void loadRectangle(const Point&, const Dimensions&, const Color&, bool fill);
};

#endif /* ENGINEV2_COMPONENTS_RECTANGLECOMPONENT_H_ */
