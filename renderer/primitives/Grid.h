#ifndef RENDERER_PRIMITIVES_GRID_H_
#define RENDERER_PRIMITIVES_GRID_H_

#include <vector>

#include "renderer/drawable/Drawable.h"
#include "renderer/primitives/Line.h"
#include "renderer/primitives/Point.h"

struct Renderer;

class Grid : public Drawable {
public:
	Grid(Point origin, float cellWidth, float cellHeight, float fullWidth, float fullHeight);

	void draw(Renderer&);
private:
	std::vector<Line> lines;
};

#endif /* RENDERER_PRIMITIVES_GRID_H_ */
