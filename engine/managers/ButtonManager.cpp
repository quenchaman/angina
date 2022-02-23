#include "ButtonManager.h"

#include <iostream>

#include "platform/sdl/events/InputEvent.h"
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Object.h"
#include "engine/components/buttons/BaseButton.h"
#include "renderer/utils/PrimitivesUtils.h"

void ButtonManager::registerButton(const int32_t id, BaseButton& btn) {
	buttons[id] = &btn;
}

void ButtonManager::invokeCallback(const InputEvent& event) {
	if (event.type != EventType::MOUSE_RELEASE) {
		return;
	}

	int32_t clickX = event.posX;
	int32_t clickY = event.posY;
	Point clickPoint = { clickX, clickY };

	for (auto const& [id, button] : buttons) {
		if (PrimitivesUtils::isInRect(button->getPosition(), button->getDimensions(), clickPoint)) {
			button->getCallback()();
		}
	}
}

BaseButton& ButtonManager::getButton(int32_t id) {
	return *buttons[id];
}

std::unordered_map<int32_t, BaseButton*>& ButtonManager::getButtons() {
	return buttons;
}

ButtonManager::~ButtonManager() {
	for (auto const& [id, btn] : buttons) {
		delete btn;
	}

	std::cout << "Buttons destroyed" << std::endl;
}
