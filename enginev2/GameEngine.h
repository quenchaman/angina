#ifndef ENGINEV2_GAMEENGINE_H_
#define ENGINEV2_GAMEENGINE_H_

#include <string>
#include <cstdint>

#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/events/GlobalInputComponent.h"

class GameEngine {
public:
	virtual ~GameEngine() = default;

	void init(const std::string& appTitle, int32_t width, int32_t height);
	void start();
private:
	Window win;
	GlobalInputComponent inputComponent;
	bool gameOver = false;
};

#endif /* ENGINEV2_GAMEENGINE_H_ */
