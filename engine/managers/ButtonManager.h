#ifndef SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_
#define SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_

#include <vector>
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
	~ButtonManager();
	void registerButton(BaseButton& btn);

	bool invokeCallback(const InputEvent& event);
private:
	std::vector<BaseButton*> buttons;
};

#endif /* SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_ */
