#include "Rect.h"

#include "renderer/Renderer.h"

const Rect Rect::ZERO(0, 0, 0, 0, Color::NONE);
const Rect Rect::UNDEFINED(10000, 10000, 0, 0, Color::NONE);

Rect::Rect(Point positionIn, Dimensions dimensionsIn, Color colorIn) {
	color = colorIn;
	rect = { positionIn.x, positionIn.y, dimensionsIn.w, dimensionsIn.h };
}

Rect::Rect(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color): Rect::Rect({x, y}, {w, h}, color) {}

bool Rect::operator==(const Rect& other) const {
	return rect.x == other.rect.x && rect.y == other.rect.y && rect.w == other.rect.w && rect.h == other.rect.h;
}

bool Rect::operator!=(const Rect& other) const {
	return !(*this == other);
}

bool Rect::isInRect(const Point& point) {
    return point.x >= rect.x && point.x <= (rect.x + rect.w) &&
    		point.y >= rect.y && point.y <= rect.y + rect.h;
}

std::ostream& operator<<(std::ostream& os, const Rect& rect) {
	return os << "X: " << rect.rect.x << "; Y: " << rect.rect.y << "; Width: " << rect.rect.w << "; Height: " << rect.rect.h << std::endl;
}

void Rect::draw(Renderer& renderer) {
	renderer.render(*this);
}
