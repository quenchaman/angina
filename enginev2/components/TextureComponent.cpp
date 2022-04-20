#include "TextureComponent.h"

#include "SDL_image.h"

#include "enginev2/graphics/sdl/renderer/TextureLoaderComponent.h"

TextureComponent::TextureComponent(): PrimitivesComponent(1000), textureLoader(nullptr) {}

void TextureComponent::init(TextureLoaderComponent& txLoader) {
    textureLoader = &txLoader;
}

void TextureComponent::loadTexture(const std::string& resourcePath) {
	SDL_Texture* texture = textureLoader->loadTexture(resourcePath);

	data.emplace_back(texture);
}

void TextureComponent::loadTexture(const std::string& resourcePath, const Rectangle& rect) {
	loadTexture(resourcePath);
	addViewPort(rect);
}
