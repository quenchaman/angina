#ifndef ENGINEV2_GAMEENGINE_H_
#define ENGINEV2_GAMEENGINE_H_

#include <string>
#include <cstdint>

#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/events/GlobalInputComponent.h"
#include "enginev2/components/SurfaceComponent.h"
#include "enginev2/components/TextureComponent.h"
#include "enginev2/graphics/sdl/renderer/SurfaceRendererComponent.h"
#include "enginev2/graphics/sdl/renderer/TextureRendererComponent.h"

class GameEngine {
public:
	virtual ~GameEngine() = default;

	void init(const std::string& appTitle, int32_t width, int32_t height);
	void start();
	void drawCPU();
	void drawGPU();
	void loadSurfaceOptim(const std::string& resourcePath);
	void loadTexture(const std::string& resourcePath);
protected:
	GlobalInputComponent inputComponent;
private:
	Window win;
	SurfaceComponent surfaceComponent;
	TextureComponent textureComponent;
	TextureRendererComponent textureRenderer;
	bool gameOver = false;

	// TODO: Remove after testing
	SurfaceRendererComponent renderer;

};

#endif /* ENGINEV2_GAMEENGINE_H_ */
