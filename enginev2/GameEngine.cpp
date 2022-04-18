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

	for (Surface& surface : surfaceComponent.surfaces) {
		renderer.drawOnSurface(*surface.surface, *win.surface);
	}

	win.update();
}

void GameEngine::drawGPU() {
	textureRenderer.clear();

	for (Texture& texture : textureComponent.textures) {
		textureRenderer.render(texture);
	}

	textureRenderer.update();
}

void GameEngine::loadSurfaceOptim(const std::string& resourcePath) {
	surfaceComponent.loadSurfaceOptim(resourcePath, win);
}

void GameEngine::loadTexture(const std::string& resourcePath) {
	textureComponent.loadSurface(resourcePath, textureRenderer);
}
