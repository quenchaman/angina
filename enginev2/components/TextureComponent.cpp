#include "TextureComponent.h"

#include "SDL_image.h"

#include "enginev2/graphics/sdl/renderer/TextureRendererComponent.h"

TextureComponent::TextureComponent(): PrimitivesComponent(1000) {}

void TextureComponent::loadTexture(const std::string& resourcePath, TextureRendererComponent& renderer) {
	SDL_Texture* texture = IMG_LoadTexture(renderer.sdlRenderer, resourcePath.c_str());

	data.emplace_back(texture);
}

void TextureComponent::loadTexture(const std::string& resourcePath, TextureRendererComponent& renderer, const Rectangle& rect) {
	loadTexture(resourcePath, renderer);
	addViewPort(rect);
}
