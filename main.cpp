#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "examples/towerdefence/TowerDefence.h"
#include "platform/sdl/init/Graphics.h"

#include "exceptions/BaseException.h"

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char **argv) {
	try {
		Graphics::boot();
		Graphics::bootImageExtension();
		Graphics::bootTTFExtensions();

		TowerDefence game;

		game.start();
	} catch (const BaseException &ex) {
		std::cerr << ex << std::endl;

		Graphics::shutdown();

		return EXIT_FAILURE;
	}

	Graphics::shutdown();

	return EXIT_SUCCESS;
}
