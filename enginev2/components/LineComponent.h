#ifndef ENGINEV2_COMPONENTS_LINECOMPONENT_H_
#define ENGINEV2_COMPONENTS_LINECOMPONENT_H_

#include "enginev2/graphics/models/Line.h"
#include "enginev2/components/PrimitivesComponent.h"

struct Point;
struct Color;

class LineComponent : public PrimitivesComponent<Line> {
public:
	void emplace(const Point&, const Point&, const Color&);
};

#endif /* ENGINEV2_COMPONENTS_LINECOMPONENT_H_ */
