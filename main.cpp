#include <cstdint>
#include <cstdlib>
#include <iostream>

#include <SDL.h>
#include "SDL_image.h"

// Globals
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;
SDL_Texture* board;

int32_t initVideo() {
	return SDL_Init(SDL_INIT_VIDEO);
}

int32_t initImages() {
	return IMG_Init(IMG_INIT_PNG);
}

void initRenderer() {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void initBoard() {
	SDL_Surface* s = IMG_Load("../resources/board.png");
	board = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);
}

void clear() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void initWindow() {
	window = SDL_CreateWindow(
			"Napushen chess",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			640,
			SDL_WINDOW_SHOWN);
}

void renderBoard() {
	SDL_RenderCopy(renderer, board, NULL, NULL);
}

void update() {
	SDL_RenderPresent(renderer);
}

void delay() {
	SDL_Delay(250);
}

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {
	initVideo();
	initImages();
	initWindow();
	initRenderer();
	initBoard();

	while (true) {
		clear();
		renderBoard();
		update();
		delay();
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
}
