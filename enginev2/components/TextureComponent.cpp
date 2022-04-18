#include "TextureComponent.h"

#include "SDL_image.h"

#include "enginev2/graphics/sdl/renderer/TextureRendererComponent.h"

const int32_t MAX_IMAGES = 1000000;

TextureComponent::TextureComponent() {
	textures.reserve(MAX_IMAGES);
}

void TextureComponent::loadSurface(const std::string& resourcePath, TextureRendererComponent& renderer) {
	SDL_Texture* texture = IMG_LoadTexture(renderer.sdlRenderer, resourcePath.c_str());

	textures.emplace_back(texture);
}
