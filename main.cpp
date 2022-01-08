#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <SDL.h>

#include "chess-entrypoint/ChessEntryPoint.h"
#include "exceptions/BaseException.h"

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {
	try {
		Engine* game = new ChessEntryPoint();

		game->start();

        delete game;
		return EXIT_SUCCESS;
	} catch (const BaseException& ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}
}
