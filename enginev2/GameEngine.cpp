#include "GameEngine.h"

#include "enginev2/graphics/commons/primitives/Dimensions.h"
#include "enginev2/graphics/commons/primitives/Width.h"
#include "enginev2/graphics/commons/primitives/Height.h"

void GameEngine::init(const std::string& appTitle, int32_t width, int32_t height) {
	win.init(appTitle, Width(width), Height(height));
	inputComponent.init();
}

void GameEngine::start() {
	while (!gameOver) {
		inputComponent.poll();

		if (inputComponent.hasExitEvent()) {
			break;
		}

		draw();
	}
}

void GameEngine::draw() {
	win.clear();

	for (Surface& surface : surfaceComponent.surfaces) {
		renderer.drawOnSurface(*surface.surface, *win.surface);
	}

	win.update();
}

void GameEngine::loadSurfaceOptim(const std::string& resourcePath) {
	surfaceComponent.loadSurfaceOptim(resourcePath, win);
}
