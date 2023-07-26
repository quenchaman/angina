#include "GameEngine.h"

#include "enginev2/graphics/models/Dimensions.h"
#include "enginev2/graphics/models/Width.h"
#include "enginev2/graphics/models/Height.h"

#include "enginev2/graphics/sdl/renderer/TextureLoaderComponent.h"
#include "enginev2/debug/Debug.h"

GameEngine::GameEngine(const std::string& appTitle, int32_t width, int32_t height)
{
	init(appTitle, width, height);
}

void GameEngine::init(const std::string& appTitle, int32_t width, int32_t height) {
	win.init(appTitle, Width(width), Height(height)); // These Width and Height classes should be enforced to the client
	rectangleComponent.init(100);
	//lineComponent.init(1000);
	inputComponent.init();
	textureRenderer.init(win, Color::BLACK);
	//objectComponent.init(textureLoader);
	textureComponent.init(100);
}

void GameEngine::start() {
  onStart();

	while (!gameOver) {
		bool hasEvents = inputComponent.poll();

		if (inputComponent.hasExitEvent()) {
			break;
		}

		if (hasEvents) {
		    handleEvent();
		}

		spriteAnimator.update();
		movementComponent.update();

		std::vector<std::pair<ID, ID>> collidedObjects = collisionDetector.resolveCollisions(objectComponent.elements());

		drawGPU();
	}
}

void GameEngine::drawGPU() {
	textureRenderer.clear();

	for (Texture& tex : textureComponent.elements()) {
		textureRenderer.render(tex);
	}

	for (Rectangle& rect : rectangleComponent.elements()) {
		textureRenderer.render(rect);
	}

	for (GameObject& obj : objectComponent.elements()) {
	    textureRenderer.render(obj);
	}

	/*for (Sprite& sprite : spriteAnimator.data) {
		textureRenderer.render(sprite);
	}*/

	textureRenderer.update();
}

std::shared_ptr<Texture> GameEngine::loadTexture(const std::string& resourcePath)
{
	SDL_Texture* tx = TextureLoaderComponent::loadTexture(textureRenderer, resourcePath);

	if (!tx) {
		DebugLog.showErrorInfo("loading texture");
	}

	return std::make_shared<Texture>(tx);
}

void GameEngine::setClearColor(const Color& color)
{
	textureRenderer.setClearColor(color);
}
