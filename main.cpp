#include <cstdint>
#include <cstdlib>
#include <iostream>

int32_t main(int32_t argc, char** argv) {

	for (int32_t i = 0; i < argc; i++) {
		std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
	}

	return EXIT_SUCCESS;
}
