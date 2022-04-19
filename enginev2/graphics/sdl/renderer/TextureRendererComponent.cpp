#include "TextureRendererComponent.h"

#include "SDL_render.h"

#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/graphics/sdl/primitives/Texture.h"
#include "enginev2/graphics/commons/primitives/Color.h"
#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/commons/primitives/Pixel.h"
#include "enginev2/graphics/commons/primitives/Line.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"

void TextureRendererComponent::init(Window& window) {
	// TODO: These hard-coded values should be made easily configurable.
	sdlRenderer = SDL_CreateRenderer( window.sdlWindow, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawBlendMode(sdlRenderer, SDL_BLENDMODE_BLEND);
}

void TextureRendererComponent::clear() {
	SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(sdlRenderer);
}

void TextureRendererComponent::render(Texture& texture) {
	SDL_RenderCopy(sdlRenderer, texture.texture, nullptr, nullptr);
}

void TextureRendererComponent::render(Rectangle& rect) {
	 SDL_SetRenderDrawColor(sdlRenderer, rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha);

	 if (rect.fill) {
		 SDL_RenderFillRect(sdlRenderer, &rect.rect);
	 } else {
		 SDL_RenderDrawRect(sdlRenderer, &rect.rect);
	 }
}

void TextureRendererComponent::render(Pixel& pixel) {
	SDL_SetRenderDrawColor(sdlRenderer, pixel.color.red, pixel.color.green, pixel.color.blue, pixel.color.alpha);
	SDL_RenderDrawPoint(sdlRenderer, pixel.position.x, pixel.position.y);
}

void TextureRendererComponent::render(Line& line) {
	SDL_SetRenderDrawColor(sdlRenderer, line.color.red, line.color.green, line.color.blue, line.color.alpha);
	SDL_RenderDrawLine(sdlRenderer, line.a.x, line.a.y, line.b.x, line.b.y);
}

void TextureRendererComponent::update() {
	SDL_RenderPresent(sdlRenderer);
}

TextureRendererComponent::~TextureRendererComponent() {
	SDL_DestroyRenderer(sdlRenderer);
}
