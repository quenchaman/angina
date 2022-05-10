#ifndef RENDERER_PRIMITIVES_LINE_H_
#define RENDERER_PRIMITIVES_LINE_H_

#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/commons/primitives/Color.h"

struct TextureRendererComponent;

class Line {
public:
	friend class TextureRendererComponent;

	Line(const Point& start, const Point& end, const Color&);

	Line operator+(const Line& other) const;
	Line operator*(int32_t scalar);
private:
	Point a;
	Point b;
	Color color;
};

#endif /* RENDERER_PRIMITIVES_LINE_H_ */
