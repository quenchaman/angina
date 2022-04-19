#include "GameEngine.h"

#include "enginev2/graphics/commons/primitives/Dimensions.h"
#include "enginev2/graphics/commons/primitives/Width.h"
#include "enginev2/graphics/commons/primitives/Height.h"

void GameEngine::init(const std::string& appTitle, int32_t width, int32_t height) {
	win.init(appTitle, Width(width), Height(height));
	inputComponent.init();
	textureRenderer.init(win);
}

void GameEngine::start() {
	while (!gameOver) {
		inputComponent.poll();

		if (inputComponent.hasExitEvent()) {
			break;
		}

		drawGPU();
	}
}

void GameEngine::drawCPU() {
	win.clear();

	for (Surface& surface : surfaceComponent.data) {
		renderer.drawOnSurface(*surface.surface, *win.surface);
	}

	win.update();
}

void GameEngine::drawGPU() {
	textureRenderer.clear();

	for(Texture& tex : textureComponent.data) {
		textureRenderer.render(tex);
	}

	for(Rectangle& rect : rectangleComponent.data) {
		textureRenderer.render(rect);
	}

	for(Line& line : lineComponent.data) {
		textureRenderer.render(line);
	}

	for(Pixel& pixel : pixelComponent.data) {
		textureRenderer.render(pixel);
	}

	for (size_t idx = 0; idx < viewPortTextureComponent.data.size(); idx++) {
		textureRenderer.render(viewPortTextureComponent.data[idx], viewPortTextureComponent.viewPorts[idx + 1]);
	}

	textureRenderer.update();
}

void GameEngine::loadSurfaceOptim(const std::string& resourcePath) {
	surfaceComponent.loadSurfaceOptim(resourcePath, win);
}

void GameEngine::loadTexture(const std::string& resourcePath) {
	textureComponent.loadTexture(resourcePath, textureRenderer);
}

void GameEngine::loadTexture(const std::string& resourcePath, const Rectangle& rect) {
	viewPortTextureComponent.loadTexture(resourcePath, textureRenderer, rect);
}

