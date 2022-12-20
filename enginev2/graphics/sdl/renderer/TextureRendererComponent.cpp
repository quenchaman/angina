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
	renderer = std::make_shared<SDL_Renderer>(SDL_CreateRenderer( window.sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ));
	SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BLENDMODE_BLEND);
}

void TextureRendererComponent::clear() {
	SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer.get());
}

void TextureRendererComponent::render(Texture& texture) {
    SDL_Rect dest{0, 0, texture.dim.w, texture.dim.h};
    SDL_RenderCopyEx(renderer.get(), texture.texture.get(), nullptr, &dest, texture.rotation, texture.center, texture.flip);
}

void TextureRendererComponent::render(GameObject& obj) {
    SDL_Rect dest{obj.pos.x, obj.pos.y, obj.tx->dim.w, obj.tx->dim.h};
    //SDL_RenderCopy(renderer.get(), obj.tx->texture, &obj.tx->clip.rect, &dest);
}

void TextureRendererComponent::render(Texture& texture, Rectangle& viewPort) {
	SDL_RenderSetViewport(renderer.get(), &viewPort.rect);
	render(texture);
}

void TextureRendererComponent::render(Rectangle& rect) {
	 SDL_SetRenderDrawColor(renderer.get(), rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha);

	 if (rect.fill) {
		 SDL_RenderFillRect(renderer.get(), &rect.rect);
	 } else {
		 SDL_RenderDrawRect(renderer.get(), &rect.rect);
	 }
}

void TextureRendererComponent::render(Pixel& pixel) {
	SDL_SetRenderDrawColor(renderer.get(), pixel.color.red, pixel.color.green, pixel.color.blue, pixel.color.alpha);
	SDL_RenderDrawPoint(renderer.get(), pixel.position.x, pixel.position.y);
}

void TextureRendererComponent::render(Line& line) {
	SDL_SetRenderDrawColor(renderer.get(), line.color.red, line.color.green, line.color.blue, line.color.alpha);
	SDL_RenderDrawLine(renderer.get(), line.a.x, line.a.y, line.b.x, line.b.y);
}

void TextureRendererComponent::update() {
	SDL_RenderPresent(renderer.get());
}

std::shared_ptr<SDL_Renderer> TextureRendererComponent::get() const
{
	return renderer;
}

TextureRendererComponent::~TextureRendererComponent() {
	SDL_DestroyRenderer(renderer.get());
}
