#include "TestEngine.h"

#include <iostream>
#include <string.h>

#include "SDL.h"
#include "SDL_image.h"

#include "resources/Resources.h"

#include "enginev2/graphics/commons/primitives/Line.h"
#include "enginev2/graphics/sdl/primitives/Texture.h"

TestEngine::TestEngine(): GameEngine(), txt(nullptr) {
	GameEngine::init("Hello SDL!", 960, 860);
}

void TestEngine::onStart() {
  //const int32_t width = 960;
  //const int32_t height = 860;
	SDL_Surface* surface = IMG_Load(Resources::Engine::maze20.c_str());
	SDL_Texture* texture = nullptr;
	SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat( surface, SDL_GetWindowPixelFormat( win.sdlWindow ), 0 );
	texture = SDL_CreateTexture( textureRenderer.sdlRenderer, SDL_GetWindowPixelFormat( win.sdlWindow ), SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h );
	Texture* wrapped = new Texture(texture);
	int32_t byteWidth;
	void* tempPixels;
	[[maybe_unused]]int32_t mWidth;

	SDL_LockTexture( texture, NULL, &tempPixels, &byteWidth );

	memcpy( tempPixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h );

	mPixels = (uint32_t*)tempPixels;
	mWidth = formattedSurface->w;
	mHeight = formattedSurface->h;
	int32_t pixelCount = (byteWidth / 4) * mHeight;

	int32_t mazeSquareSize = mWidth / cellsPerRow;
	int32_t cellCenterOffset = 1; // we want to sample the center of the square.

	for (int32_t i = 0; i < cellsPerRow; i++) {
	  int32_t y = (mazeSquareSize * i) + cellCenterOffset;

	  for (int32_t j = 0; j < cellsPerRow; j++) {
	    int32_t x = (mazeSquareSize * j) + cellCenterOffset;

	    //std::cout << "Sampling positions: x: " << x << " and y " << y << std::endl;

	    int32_t pixelValue = mPixels[y * mHeight + x];

	    if (pixelValue == 0) {
	      mazeGrid[i][j] = true;
	    } else {
	      mazeGrid[i][j] = false;
	    }
	  }
	}

	int32_t entrRow;
	const int32_t entrCol = 0;

	for (entrRow = 0; entrRow < cellsPerRow; entrRow++) {
	  if (!mazeGrid[entrRow][entrCol]) {
	    break;
	  }
	}

	int32_t exitRow;
	const int32_t exitCol = cellsPerRow - 1;

	for (exitRow = 0; exitRow < cellsPerRow; exitRow++) {
    if (!mazeGrid[exitRow][exitCol]) {
      break;
    }
  }

	std::cout << exitRow << std::endl;

	std::cout << "The enter row is " << entrRow << " and enter col is " << entrCol <<
	    " then exit row is " << exitRow << " and exit col is " << exitCol << std::endl;

	findPath(entrRow, entrCol, exitRow, exitCol);

	SDL_UnlockTexture(texture);
	std::cout << pixelCount << std::endl;
	textureComponent.loadTexture(*wrapped);
}

void TestEngine::handleEvent() {
}

void TestEngine::samplePixel(int32_t x, int32_t y) {
  std::cout << mPixels[y * mHeight + x] << std::endl;
}

void TestEngine::findPath(int32_t row, int32_t col, int32_t targetRow, int32_t targetCol) {
  //std::cout << "in the beginning" << std::endl;
  if (row < 0 || row >=cellsPerRow || col < 0 || col >= cellsPerRow) {
    return;
  }
  if (row == targetRow && col == targetCol) {
    std::cout << "Path found!" << std::endl;
    return;
  }

  //std::cout << "ooops hi" << std::endl;

  if (mazeGrid[row][col]) {
    return;
  }

  //std::cout << "hi" << std::endl;

  path.push({row, col});
  //std::cout << "after push" << std::endl;
  findPath(row + 1, col, targetRow, targetCol);
  //wstd::cout << "After going down" << std::endl;
  findPath(row - 1, col, targetRow, targetCol);
  findPath(row, col + 1, targetRow, targetCol);
  findPath(row, col - 1, targetRow, targetCol);
  path.pop();
}

