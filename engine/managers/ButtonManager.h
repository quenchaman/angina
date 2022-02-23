#ifndef SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_
#define SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_

#include <unordered_map>
#include <cstdint>

struct BaseButton;
struct InputEvent;
struct Texture;
struct Renderer;

/**
 * Holds reference to all buttons and gets called to check whether a button has been clicked.
 * On a button click, invokes the callback of the button.
 */
class ButtonManager {
public:
	ButtonManager() = default;
	~ButtonManager();

	void registerButton(const int32_t id, BaseButton& btn);

	void invokeCallback(const InputEvent& event);

	BaseButton& getButton(int32_t id);

	std::unordered_map<int32_t, BaseButton*>& getButtons();
private:
	std::unordered_map<int32_t, BaseButton*> buttons;
};

#endif /* SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_ */
