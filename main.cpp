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

		int32_t idx = engine.textureComponent.loadTexture(Resources::Engine::sticky);
		Texture& tx = engine.textureComponent.getTexture(idx);
		engine.animationComponent.init(tx, 4, 60);

		Rectangle frame1(Point{0, 0}, Dimensions{64, 205});
		Rectangle frame2(Point{64, 0}, Dimensions{64, 205});
		Rectangle frame3(Point{128, 0}, Dimensions{64, 205});
		Rectangle frame4(Point{192, 0}, Dimensions{64, 205});

		engine.animationComponent.addFrame(frame1);
		engine.animationComponent.addFrame(frame2);
		engine.animationComponent.addFrame(frame3);
		engine.animationComponent.addFrame(frame4);

		engine.start();
	} catch (const BaseException &ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
