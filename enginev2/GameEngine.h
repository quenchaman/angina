#ifndef ENGINEV2_GAMEENGINE_H_
#define ENGINEV2_GAMEENGINE_H_

#include <string>
#include <cstdint>

#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/events/GlobalInputComponent.h"
#include "enginev2/components/SurfaceComponent.h"
#include "enginev2/components/TextureComponent.h"
#include "enginev2/components/RectangleComponent.h"
#include "enginev2/components/PixelComponent.h"
#include "enginev2/components/LineComponent.h"
#include "enginev2/components/GameObjectComponent.h"
#include "enginev2/components/AnimationComponent.h"
#include "enginev2/graphics/sdl/renderer/SurfaceRendererComponent.h"
#include "enginev2/graphics/sdl/renderer/TextureRendererComponent.h"
#include "enginev2/graphics/sdl/renderer/TextureLoaderComponent.h"

struct Rectangle;

class GameEngine {
public:
    GameEngine() = default;
	virtual ~GameEngine() = default;

	void init(const std::string& appTitle, int32_t width, int32_t height);
	void start();

	virtual void onStart() = 0;
	virtual void handleEvent() = 0;

	void drawCPU();
	void drawGPU();

	void loadSurfaceOptim(const std::string& resourcePath);
protected:
	RectangleComponent rectangleComponent;
	PixelComponent pixelComponent;
	LineComponent lineComponent;
	GameObjectComponent objectComponent;
	TextureComponent textureComponent;
	AnimationComponent animationComponent;
	GlobalInputComponent inputComponent;
private:
	Window win;
	SurfaceComponent surfaceComponent;

	TextureComponent viewPortTextureComponent;

	TextureRendererComponent textureRenderer;
	TextureLoaderComponent textureLoader;
	bool gameOver = false;

	// TODO: Remove after testing
	SurfaceRendererComponent renderer;
};

#endif /* ENGINEV2_GAMEENGINE_H_ */
