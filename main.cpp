#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <SDL.h>

#include <nlohmann/json.hpp>
#include "aota/Aota.h"

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {
	try {
		Graphics::boot();
		Graphics::bootImageExtension();

		Engine* engine = new Aota();

		engine->start();

		return EXIT_SUCCESS;
	} catch (const BaseException& ex) {
		std::cerr << ex << std::endl;

		return EXIT_FAILURE;
	}
}
