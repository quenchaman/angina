#ifndef RENDERER_PRIMITIVES_LINE_H_
#define RENDERER_PRIMITIVES_LINE_H_

#include "renderer/primitives/Point.h"
#include "renderer/primitives/Color.h"

struct TextureRendererComponent;

class Line {
public:
	friend class TextureRendererComponent;

	Line(const Point& start, const Point& end, const Color&);

private:
	Point a;
	Point b;
	Color color;
};

#endif /* RENDERER_PRIMITIVES_LINE_H_ */
