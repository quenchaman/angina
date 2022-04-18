#include "Rectangle.h"

#include "enginev2/graphics/commons/primitives/Dimensions.h"
#include "enginev2/graphics/commons/primitives/Point.h"

Rectangle::Rectangle(const Point& pos, const Dimensions& dim, const Color& col): rect(SDL_Rect {pos.x, pos.y, dim.w, dim.h}), color(col) {}

