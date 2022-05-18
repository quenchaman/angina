#include "TestEngine.h"

#include <iostream>
#include <string.h>

#include "SDL.h"
#include "SDL_image.h"

#include "resources/Resources.h"

#include "enginev2/graphics/commons/primitives/Line.h"

TestEngine::TestEngine(): GameEngine(), txt(nullptr) {
	GameEngine::init("Hello SDL!", 960, 860);
}

void TestEngine::onStart() {
  //const int32_t width = 960;
  //const int32_t height = 860;
	SDL_Surface* surface = IMG_Load(Resources::Engine::arrow.c_str());
	SDL_Texture* texture = nullptr;
	SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat( surface, SDL_GetWindowPixelFormat( win.sdlWindow ), 0 );
	texture = SDL_CreateTexture( textureRenderer.sdlRenderer, SDL_GetWindowPixelFormat( win.sdlWindow ), SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h );

	void* mPixels;
	int32_t mPitch;
	[[maybe_unused]]int32_t mWidth;
	int32_t mHeight;

	SDL_LockTexture( texture, NULL, &mPixels, &mPitch );

	memcpy( mPixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h );

	[[maybe_unused]]uint32_t* pixels = (uint32_t*)mPixels;
	mWidth = formattedSurface->w;
	mHeight = formattedSurface->h;
	int32_t pixelCount = (mPitch / 4) * mHeight;

	std::cout << pixelCount << std::endl;

}

void TestEngine::handleEvent() {

}

