#ifndef ENGINEV2_COMPONENTS_LINECOMPONENT_H_
#define ENGINEV2_COMPONENTS_LINECOMPONENT_H_

#include <vector>

#include "enginev2/graphics/commons/primitives/Line.h"

struct Point;
struct Color;
struct GameEngine;

class LineComponent {
public:
	friend class GameEngine;
	LineComponent();

	void loadLine(const Point&, const Point&, const Color&);
private:
	std::vector<Line> lines;
};

#endif /* ENGINEV2_COMPONENTS_LINECOMPONENT_H_ */
