#ifndef ENGINEV2_COMPONENTS_RECTANGLECOMPONENT_H_
#define ENGINEV2_COMPONENTS_RECTANGLECOMPONENT_H_

#include <vector>

#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/commons/primitives/Dimensions.h"

struct GameEngine;

class RectangleComponent {
public:
	friend class GameEngine;

	RectangleComponent();

	void loadRectangle(const Point&, const Dimensions&, const Color&, bool fill);
private:
	std::vector<Rectangle> rectangles;
};

#endif /* ENGINEV2_COMPONENTS_RECTANGLECOMPONENT_H_ */
