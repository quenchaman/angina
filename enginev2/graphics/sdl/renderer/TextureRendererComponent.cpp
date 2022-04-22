#include "TextureRendererComponent.h"

#include "SDL_render.h"
#include "SDL_shape.h"

#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/graphics/sdl/primitives/Texture.h"
#include "enginev2/graphics/commons/primitives/Color.h"
#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/commons/primitives/Pixel.h"
#include "enginev2/graphics/commons/primitives/Line.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "enginev2/models/GameObject.h"

void TextureRendererComponent::init(Window& window) {
	// TODO: These hard-coded values should be made easily configurable.
	sdlRenderer = SDL_CreateRenderer( window.sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	SDL_SetRenderDrawBlendMode(sdlRenderer, SDL_BLENDMODE_BLEND);
}

void TextureRendererComponent::clear() {
	SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(sdlRenderer);
}

void TextureRendererComponent::render(Texture& texture) {
    SDL_Rect dest{0, 0, texture.clip.rect.w, texture.clip.rect.h};
    SDL_RenderCopy(sdlRenderer, texture.texture, &texture.clip.rect, &dest);
}

void TextureRendererComponent::render(GameObject& obj) {
    SDL_Rect dest{obj.pos.x, obj.pos.y, obj.tx->dim.w, obj.tx->dim.h};
    SDL_RenderCopy(sdlRenderer, obj.tx->texture, &obj.tx->clip.rect, &dest);
}

void TextureRendererComponent::render(Texture& texture, Rectangle& viewPort) {
	SDL_RenderSetViewport(sdlRenderer, &viewPort.rect);
	render(texture);
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
