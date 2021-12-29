/*
 * ButtonManager.h
 *
 *  Created on: Dec 29, 2021
 *      Author: ubuntu
 */

#ifndef SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_
#define SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_

#include <unordered_map>
#include <cstdint>

struct Button;
struct InputEvent;

class ButtonManager {
public:
	ButtonManager() = default;
	~ButtonManager() = default;

	void registerButton(int32_t id, Button* btn);
	int32_t getClickedButtonIndex(const InputEvent& event);
private:
	std::unordered_map<int32_t, Button*> buttons;
};

#endif /* SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_ */
