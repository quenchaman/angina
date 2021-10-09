#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <SDL.h>

SDL_Window* window = nullptr;
SDL_Surface* globalScreenSurface = nullptr;
SDL_Surface* imageSurface = nullptr;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {

	if (SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS) {
		std::cout << "Could not initialize graphics - " << SDL_GetError() << std::endl;

		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cerr << "SDL_CreateWindow() failed with reason - " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	globalScreenSurface = SDL_GetWindowSurface(window);

	if (globalScreenSurface == nullptr) {
		std::cerr << "SDL_GetWindowSurface failed with reason - " << SDL_GetError() << std::endl;

		return EXIT_FAILURE;
	}

	const std::string path = "../assets/hello.bmp";

	imageSurface = SDL_LoadBMP(path.c_str());

	if (imageSurface == nullptr) {
		std::cerr << "SDL_LoadBMP() failed with reason - " << SDL_GetError() << std::endl;

		return EXIT_FAILURE;
	}

	SDL_BlitSurface(imageSurface, NULL, globalScreenSurface, NULL);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(5000);


	return EXIT_SUCCESS;
}
