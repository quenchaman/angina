#include "TextureComponent.h"

#include "SDL_image.h"

#include "enginev2/graphics/sdl/renderer/TextureLoaderComponent.h"

void TextureComponent::init(std::shared_ptr<TextureRendererComponent> renderer)
{
	this->rendererPtr = renderer;
}

Texture& TextureComponent::load(const std::string& pathToTextureFile) {
	data.emplace_back(TextureLoaderComponent::loadTexture(*rendererPtr, pathToTextureFile));

	return data[data.size() - 1];
}
