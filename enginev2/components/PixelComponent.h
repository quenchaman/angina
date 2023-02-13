#ifndef ENGINEV2_COMPONENTS_PIXELCOMPONENT_H_
#define ENGINEV2_COMPONENTS_PIXELCOMPONENT_H_

#include "enginev2/graphics/models/Pixel.h"

#include "enginev2/components/PrimitivesComponent.h"

struct Point;
struct Color;

class PixelComponent : public PrimitivesComponent<Pixel> {
public:
	PixelComponent();

	void loadPixel(const Point&, const Color&);
};

#endif /* ENGINEV2_COMPONENTS_PIXELCOMPONENT_H_ */
