#include "GameEngine.h"

#include "enginev2/graphics/commons/primitives/Dimensions.h"
#include "enginev2/graphics/commons/primitives/Width.h"
#include "enginev2/graphics/commons/primitives/Height.h"

#include "enginev2/graphics/sdl/renderer/TextureLoaderComponent.h"

GameEngine::GameEngine(const std::string& appTitle, int32_t width, int32_t height)
{
	init(appTitle, width, height);
}

void GameEngine::init(const std::string& appTitle, int32_t width, int32_t height) {
	win.init(appTitle, Width(width), Height(height));
	rectangleComponent.init(100);
	//lineComponent.init(1000);
	inputComponent.init();
	textureRenderer.init(win, Color::BLACK);
	//objectComponent.init(textureLoader);
	textureComponent.init(std::make_shared<TextureRendererComponent>(textureRenderer));
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

		drawGPU();
	}
}

void GameEngine::drawGPU() {
	textureRenderer.clear();

	for(Texture& tex : textureComponent.data) {
		textureRenderer.render(tex);
	}

	for(Rectangle& rect : rectangleComponent.data) {
		textureRenderer.render(rect);
	}
	/*
	for(Line& line : lineComponent.data) {
		textureRenderer.render(line);
	}

	for(Pixel& pixel : pixelComponent.data) {
		textureRenderer.render(pixel);
	}

	for(GameObject& obj : objectComponent.data) {
	    textureRenderer.render(obj);
	}*/

	for (Sprite& sprite : spriteAnimator.data) {
		textureRenderer.render(sprite);
	}

	textureRenderer.update();
}

SDL_Texture* GameEngine::loadTexture(const std::string& resourcePath)
{
	return TextureLoaderComponent::loadTexture(textureRenderer, resourcePath);
}

void GameEngine::setClearColor(const Color& color)
{
	textureRenderer.setClearColor(color);
}
