#include "ButtonManager.h"

#include <iostream>

#include "platform/sdl/events/InputEvent.h"
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Object.h"
#include "engine/components/buttons/BaseButton.h"
#include "renderer/utils/PrimitivesUtils.h"

void ButtonManager::registerButton(BaseButton &btn) {
    buttons.push_back(&btn);
}

bool ButtonManager::invokeCallback(const InputEvent &event) {
    if (event.type != EventType::MOUSE_RELEASE) {
        return false;
    }

    Point clickPoint = { event.posX, event.posY };

    std::cout << "Clicked at " << clickPoint << std::endl;

    for (auto const &button : buttons) {
        if (PrimitivesUtils::isInRect(button->getPosition(),
                button->getDimensions(), clickPoint)) {
            button->getCallback()();

            return true;
        }
    }

    return false;
}

void ButtonManager::clear() {
    buttons.clear();
}

ButtonManager::~ButtonManager() {
    clear();

    std::cout << "Buttons destroyed" << std::endl;
}
