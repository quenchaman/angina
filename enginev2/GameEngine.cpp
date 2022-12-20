#include "GameEngine.h"

#include "enginev2/graphics/commons/primitives/Dimensions.h"
#include "enginev2/graphics/commons/primitives/Width.h"
#include "enginev2/graphics/commons/primitives/Height.h"

void GameEngine::init(const std::string& appTitle, int32_t width, int32_t height) {
	win.init(appTitle, Width(width), Height(height));
	//lineComponent.init(1000);
	inputComponent.init();
	textureRenderer.init(win);
	//objectComponent.init(textureLoader);
	textureComponent.init(std::make_shared<TextureRendererComponent>(textureRenderer));
}

void GameEngine::start() {
  onStart();

	std::cout << sizeof(Line) << std::endl;

	while (!gameOver) {
		bool hasEvents = inputComponent.poll();

		if (inputComponent.hasExitEvent()) {
			break;
		}

		if (hasEvents) {
		    handleEvent();
		}

		drawGPU();
	}
}

void GameEngine::drawGPU() {
	textureRenderer.clear();

	for(Texture& tex : textureComponent.data) {
		textureRenderer.render(tex);
	}

	/*for(Rectangle& rect : rectangleComponent.data) {
		textureRenderer.render(rect);
	}

	for(Line& line : lineComponent.data) {
		textureRenderer.render(line);
	}

	for(Pixel& pixel : pixelComponent.data) {
		textureRenderer.render(pixel);
	}

	for(GameObject& obj : objectComponent.data) {
	    textureRenderer.render(obj);
	}*/

	for (size_t idx = 0; idx < textureComponent.data.size(); idx++) {
		textureRenderer.render(textureComponent.data[idx]);
	}

	textureRenderer.update();
}

