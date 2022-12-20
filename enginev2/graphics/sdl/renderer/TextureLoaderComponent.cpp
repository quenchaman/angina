#include "TextureLoaderComponent.h"

#include "enginev2/graphics/sdl/renderer/TextureRendererComponent.h"

std::shared_ptr<SDL_Texture> TextureLoaderComponent::loadTexture(TextureRendererComponent& renderer, const std::string& resourcePath)
{
  return std::make_shared<SDL_Texture>(IMG_LoadTexture(renderer.get().get(), resourcePath.c_str()));
}
