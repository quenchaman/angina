#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "SDL.h"

#include "enginev2/graphics/sdl/init/Graphics.h"
#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/graphics/sdl/primitives/Surface.h"
#include "enginev2/graphics/commons/primitives/Width.h"
#include "enginev2/graphics/commons/primitives/Height.h"
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
		engine.init("Hello SDL", screenW, screenH	);

		engine.rectangleComponent.loadRectangle(Point{screenW / 4, screenH / 4}, Dimensions {screenW / 2, screenH / 2}, Color::RED, true);
		engine.rectangleComponent.loadRectangle(Point{screenW / 6, screenH / 6}, Dimensions {screenW * 2 / 3, screenH * 2 / 3}, Color::GREEN, false);

		for (int32_t y = screenH / 4; y < screenH / 4 + screenH / 2; y += 4) {
			engine.pixelComponent.loadPixel(Point {screenW / 2, y}, Color::GREEN);
		}

		engine.lineComponent.loadLine(Point {0, screenH / 2}, Point {screenW, screenH / 2}, Color::BLUE);

		engine.start();
	} catch (const BaseException &ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
