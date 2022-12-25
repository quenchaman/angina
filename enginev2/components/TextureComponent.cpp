#include "TextureComponent.h"

#include "SDL_image.h"

#include "enginev2/graphics/sdl/renderer/TextureLoaderComponent.h"

void TextureComponent::init(std::shared_ptr<TextureRendererComponent> renderer)
{
	this->rendererPtr = renderer;
}

Texture& TextureComponent::add(SDL_Texture* texture) {
	data.emplace_back(texture);

	return data[data.size() - 1];
}
