#ifndef ENGINEV2_COMPONENTS_PIXELCOMPONENT_H_
#define ENGINEV2_COMPONENTS_PIXELCOMPONENT_H_

#include <vector>

#include "enginev2/graphics/commons/primitives/Pixel.h"

struct Point;
struct Color;
struct GameEngine;

class PixelComponent {
public:
	friend class GameEngine;

	PixelComponent();

	void loadPixel(const Point&, const Color&);
private:
	std::vector<Pixel> pixels;
};

#endif /* ENGINEV2_COMPONENTS_PIXELCOMPONENT_H_ */
