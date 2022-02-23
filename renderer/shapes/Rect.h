#ifndef SDL_PRIMITIVES_RECT_H_
#define SDL_PRIMITIVES_RECT_H_

#include <iostream>

#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Color.h"
#include "renderer/drawable/Drawable.h"

#include "SDL_shape.h"

class Rect : public Drawable {
public:
	Rect(Point positionIn, Dimensions dimensionsIn, Color colorIn);
	Rect(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color);

	void draw(Renderer& renderer);

	bool operator==(const Rect& other) const;
	bool operator!=(const Rect& other) const;

	SDL_Rect getRawRect() const;
	Color getColor() const;

	bool isInRect(const Point& point);

	static const Rect ZERO;
	static const Rect UNDEFINED;

	friend std::ostream& operator<<(std::ostream& os, const Rect& rect);
private:
	SDL_Rect rect;
	Color color;
};

#endif /* SDL_PRIMITIVES_RECT_H_ */
