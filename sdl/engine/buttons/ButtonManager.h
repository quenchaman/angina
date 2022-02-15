#ifndef SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_
#define SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_

#include <unordered_map>
#include <cstdint>

struct Button;
struct InputEvent;
struct Texture;
struct Renderer;

class ButtonManager {
public:
	ButtonManager() = default;
	~ButtonManager();

	void registerButton(const int32_t id, const Button& btn);

	int32_t getClickedButtonIndex(const InputEvent& event);

	Button& getButton(int32_t id);

	std::unordered_map<int32_t, Button*>& getButtons();

	void setPosition(int32_t btnIdx, int32_t x, int32_t y);
private:
	std::unordered_map<int32_t, Button*> buttons;
};

#endif /* SDL_ENGINE_BUTTONS_BUTTONMANAGER_H_ */
