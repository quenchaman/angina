/*
 * InputEvent.h
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */

#ifndef SDLUTILS_INPUTEVENT_H_
#define SDLUTILS_INPUTEVENT_H_

#include <cstdint>

#include "sdl/primitives/Point.h"
#include "sdl/events/EventDefines.h"

union SDL_Event;

class InputEvent {
public:
	int32_t init();
	void deinit();
	bool poll();
	bool hasExitEvent() const;

	Point pos = Point::UNDEFINED;
	int32_t key = Keyboard::KEY_UNKNOWN;
	int8_t mouseButton = Mouse::UNKNOWN;
	TouchEvent touchEvent = TouchEvent::UNKNOWN;
	EventType::EventDataTypes type = EventType::UNKNOWN;
private:
	void setEventTypeInternal();

	SDL_Event* sdlEvent = nullptr;
};

#endif /* SDLUTILS_INPUTEVENT_H_ */
