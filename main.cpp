#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <SDL.h>

#include <nlohmann/json.hpp>
#include "test/Test.h"

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {
	try {
		Test* game = new Test();

		game->start();

        delete game;
		return EXIT_SUCCESS;
	} catch (const BaseException& ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}
}
