#include "ButtonManager.h"

#include "platform/sdl/events/InputEvent.h"
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Object.h"
#include "platform/sdl/shapes/Rect.h"
#include "renderer/primitives/Button.h"

void ButtonManager::registerButton(const int32_t id, Button& btn) {
	buttons[id] = &btn;
}

int32_t ButtonManager::getClickedButtonIndex(const InputEvent& event) {
	if (event.type != EventType::MOUSE_RELEASE) {
		return -1;
	}

	int32_t clickX = event.posX;
	int32_t clickY = event.posY;
	Point clickPoint = { clickX, clickY };

	for (auto const& [id, button] : buttons) {
		if (button->rectangle.isInRect(clickPoint)) {
			return id;
		}
	}

	return -1;
}

Button& ButtonManager::getButton(int32_t id) {
	return *buttons[id];
}

std::unordered_map<int32_t, Button*>& ButtonManager::getButtons() {
	return buttons;
}

void ButtonManager::setPosition(int32_t btnIdx, int32_t x, int32_t y) {
	getButton(btnIdx).move(x, y);
}

ButtonManager::~ButtonManager() {
	for (auto const& [id, btn] : buttons) {
		delete btn;
	}

	std::cout << "Buttons destroyed" << std::endl;
}
