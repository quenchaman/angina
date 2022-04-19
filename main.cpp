#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "SDL.h"

#include "enginev2/graphics/sdl/init/Graphics.h"
#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/graphics/sdl/primitives/Surface.h"
#include "enginev2/graphics/commons/primitives/Width.h"
#include "enginev2/graphics/commons/primitives/Height.h"
#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/sdl/renderer/SurfaceRendererComponent.h"
#include "enginev2/GameEngine.h"
#include "resources/Resources.h"

#include "exceptions/BaseException.h"

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char **argv) {
	try {
		Graphics g;
		g.init();
		GameEngine engine;
		const int32_t screenW = 640;
		const int32_t screenH = 480;
		engine.init("Hello SDL", screenW, screenH);

		Rectangle topleftViewport(Point::ZERO, Dimensions {screenW / 2, screenH / 2});
		Rectangle toprightViewport(Point{screenW / 2, 0}, Dimensions {screenW / 2, screenH / 2});
		Rectangle bottomViewport(Point{0, screenH / 2}, Dimensions {screenW, screenH / 2});

		engine.loadTexture(Resources::Engine::eye, topleftViewport);
		engine.loadTexture(Resources::Engine::eye, toprightViewport);
		engine.loadTexture(Resources::Engine::eye, bottomViewport);

		engine.start();
	} catch (const BaseException &ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
