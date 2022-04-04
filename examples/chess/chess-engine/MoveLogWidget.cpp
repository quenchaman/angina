#include "MoveLogWidget.h"

#include "renderer/repositories/TextRepository.h"
#include "renderer/primitives/Text.h"
#include "platform/sdl/primitives/Font.h"
#include "engine/components/textstack/TextStack.h"
#include "engine/factory/GraphicsFactory.h"
#include "platform/ids/ReverseIdGenerator.h"

MoveLogWidget::MoveLogWidget(Point pos, GraphicsFactory &factory, Font &f,
		uint32_t cap) :
		Widget(pos), textFactory(factory), font(f), sizeCap(cap), yOffset(0) {
}

void MoveLogWidget::add(std::string text, int32_t textWidth, Color color) {
	if (textLineIds.size() == sizeCap) {
		removeLastLine();
	}

	/*
	 * Push all existing lines to the bottom
	 */
	for (auto const& [id, drawable] : drawables) {
		Object *obj = (Object*) drawable;
		Point currentPosition = obj->getPosition();
		obj->move(currentPosition.x, currentPosition.y + font.getSize());
	}

	/*
	 * Add new line at the top
	 */
	Text *textTexture = textFactory.createText(text, font, Point::ZERO,
			Dimensions { textWidth, font.getSize() }, color);
	int32_t id = put(*(Object*) textTexture);
	textLineIds.push_front(id);
}

void MoveLogWidget::removeLastLine() {
	int32_t idRem = textLineIds.back();
	textLineIds.pop_back();
	remove(idRem);
}
