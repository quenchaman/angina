#ifndef ENGINEV2_GAMEENGINE_H_
#define ENGINEV2_GAMEENGINE_H_

#include <string>
#include <cstdint>
#include <memory>

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
#include "enginev2/storage/Container.h"
#include "renderer/primitives/Line.h"

#include "enginev2/graphics/animation/SpriteAnimator.h"

class Rectangle;

class GameEngine {
public:
  GameEngine() = default;
	GameEngine(const std::string& appTitle, int32_t width, int32_t height);
	virtual ~GameEngine() = default;

	void init(const std::string& appTitle, int32_t width, int32_t height);
	void start();

	virtual void onStart() = 0;
	virtual void onUpdate() = 0;
	virtual void handleEvent() = 0;

	void drawGPU();
protected:
	RectangleComponent rectangleComponent;
  //PixelComponent pixelComponent;
  //LineComponent lineComponent;
  GameObjectComponent objectComponent;
  TextureComponent textureComponent;
	SpriteAnimator spriteAnimator;
  //AnimationComponent animationComponent;
	GlobalInputComponent inputComponent;

	// TODO: Extract the helper method into a class and add it here so a client can easily namespace-use methods
	std::shared_ptr<Texture> loadTexture(const std::string& resourcePath);

	void setClearColor(const Color&);
private:
	Window win;
	TextureRendererComponent textureRenderer;
	bool gameOver = false;
};

#endif /* ENGINEV2_GAMEENGINE_H_ */
