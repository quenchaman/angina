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

		Rectangle rect1(Point{0,0}, Dimensions{100, 100});
		Rectangle rect2(Point{100,0}, Dimensions{100, 100});
		Rectangle rect3(Point{0,100}, Dimensions{100, 100});
		Rectangle rect4(Point{100,100}, Dimensions{100, 100});

		engine.objectComponent.loadGameObjectSprite(Resources::Engine::balls, Point::ZERO, rect1);
		engine.objectComponent.loadGameObjectSprite(Resources::Engine::balls, Point{205, 0}, rect2);
		engine.objectComponent.loadGameObjectSprite(Resources::Engine::balls, Point{0, 205}, rect3);
		engine.objectComponent.loadGameObjectSprite(Resources::Engine::balls, Point{205, 205}, rect4);

		engine.start();
	} catch (const BaseException &ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
