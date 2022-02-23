#ifndef SDLUTILS_INPUTEVENT_H_
#define SDLUTILS_INPUTEVENT_H_

#include <cstdint>

#include "platform/sdl/events/EventDefines.h"

union SDL_Event;

class InputEvent {
public:
	int32_t init();
	void deinit();
	bool poll();
	bool hasExitEvent() const;

	int32_t posX;
	int32_t posY;
	int32_t key = Keyboard::KEY_UNKNOWN;
	int8_t mouseButton = Mouse::UNKNOWN;
	TouchEvent touchEvent = TouchEvent::UNKNOWN;
	EventType::EventDataTypes type = EventType::UNKNOWN;
private:
	void setEventTypeInternal();

	SDL_Event* sdlEvent = nullptr;
};

#endif /* SDLUTILS_INPUTEVENT_H_ */
