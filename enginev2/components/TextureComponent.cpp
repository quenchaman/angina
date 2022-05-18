#include "TextureComponent.h"

#include "SDL_image.h"

#include "enginev2/graphics/sdl/renderer/TextureLoaderComponent.h"

TextureComponent::TextureComponent(): PrimitivesComponent(1000), textureLoader(nullptr) {}

void TextureComponent::init(TextureLoaderComponent& txLoader) {
    textureLoader = &txLoader;
}

int32_t TextureComponent::loadTexture(const std::string& resourcePath) {
	SDL_Texture* texture = textureLoader->loadTexture(resourcePath);

	data.emplace_back(texture);

	return static_cast<int32_t>(data.size()) - 1;
}

void TextureComponent::loadSpriteTexture(const std::string& resourcePath, const Rectangle& clip) {
    SDL_Texture* texture = textureLoader->loadTexture(resourcePath);

    data.emplace_back(texture, clip);
}

void TextureComponent::loadTexture(const std::string& resourcePath, const Rectangle& rect) {
	loadTexture(resourcePath);
	addViewPort(rect);
}

Texture& TextureComponent::getTexture(int32_t id) {
    return data[id];
}

void TextureComponent::loadTexture(Texture& t) {
  data.push_back(t);
}
