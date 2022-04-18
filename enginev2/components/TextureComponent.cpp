#include "TextureComponent.h"

#include "SDL_image.h"

#include "enginev2/graphics/sdl/renderer/TextureRendererComponent.h"
#include "enginev2/graphics/sdl/primitives/Surface.h"

const int32_t MAX_IMAGES = 1000000;

TextureComponent::TextureComponent() {
	textures.reserve(MAX_IMAGES);
}

void TextureComponent::loadSurface(const std::string& resourcePath, TextureRendererComponent& renderer) {
	Surface surface(resourcePath);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.sdlRenderer, surface.surface);

	textures.emplace_back(texture);
}
