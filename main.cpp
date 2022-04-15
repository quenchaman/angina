#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "SDL.h"

#include "enginev2/graphics/sdl/init/Graphics.h"
#include "enginev2/graphics/sdl/window/Window.h"
//#include "platform/sdl/resource-loader/ResourceLoader.h"
#include "enginev2/graphics/sdl/renderer/SurfaceRenderer.h"
#include "enginev2/graphics/sdl/primitives/Surface.h"
#include "enginev2/graphics/commons/primitives/Width.h"
#include "enginev2/graphics/commons/primitives/Height.h"
#include "resources/Resources.h"

#include "exceptions/BaseException.h"

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char **argv) {
	try {
		Graphics g;
		g.init();
		Window win;
		win.init("Hello SDL", Width(640), Height(480));

		SurfaceRenderer render;
		Surface s(Resources::TD::background);
		SDL_Rect sourceRect = {0, 0, 640, 480};

		SDL_Rect destinationRect1 = SDL_Rect {0, 0, 640/2, 480/2};
		render.drawOnSurface(s.getSurface(), sourceRect, *win.surface, destinationRect1);

		win.update();
	} catch (const BaseException &ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
