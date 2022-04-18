#ifndef ENGINEV2_GAMEENGINE_H_
#define ENGINEV2_GAMEENGINE_H_

#include <string>
#include <cstdint>

#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/events/GlobalInputComponent.h"
#include "enginev2/components/SurfaceComponent.h"
#include "enginev2/graphics/sdl/renderer/SurfaceRenderer.h"

class GameEngine {
public:
	virtual ~GameEngine() = default;

	void init(const std::string& appTitle, int32_t width, int32_t height);
	void start();
	void draw();
	void loadSurfaceOptim(const std::string& resourcePath);

	SurfaceComponent surfaceComponent;
protected:
	GlobalInputComponent inputComponent;
private:
	Window win;
	bool gameOver = false;

	// TODO: Remove after testing
	SurfaceRenderer renderer;

};

#endif /* ENGINEV2_GAMEENGINE_H_ */
