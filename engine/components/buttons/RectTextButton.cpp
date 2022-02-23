#include "RectTextButton.h"

#include "renderer/shapes/Rect.h"
#include "renderer/Renderer.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Text.h"

RectTextButton::RectTextButton(Point p, Dimensions dim, Color backgroundColor, Text& t, void (*clb)()):
	BaseButton(p, dim, clb), rect(new Rect(p, dim, backgroundColor)), text(&t) {}

void RectTextButton::draw(Renderer& renderer) {
	renderer.render(*rect);
	renderer.render(dynamic_cast<Object&>(*text));
}

RectTextButton::~RectTextButton() {

}
