#include "TextureRendererComponent.h"

#include "SDL_render.h"

#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/graphics/sdl/primitives/Texture.h"

void TextureRendererComponent::init(Window& window) {
	// TODO: These hard-coded values should be made easily configurable.
	sdlRenderer = SDL_CreateRenderer( window.sdlWindow, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawBlendMode(sdlRenderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void TextureRendererComponent::clear() {
	SDL_RenderClear(sdlRenderer);
}

void TextureRendererComponent::render(Texture& texture) {
	SDL_RenderCopy(sdlRenderer, texture.texture, nullptr, nullptr);
}

void TextureRendererComponent::update() {
	SDL_RenderPresent( sdlRenderer );
}
