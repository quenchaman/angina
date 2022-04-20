#include "TextureLoaderComponent.h"

#include "SDL_image.h"

#include "enginev2/graphics/sdl/renderer/TextureRendererComponent.h"

void TextureLoaderComponent::init(TextureRendererComponent& r) {
    renderer = &r;
}

SDL_Texture* TextureLoaderComponent::loadTexture(const std::string& resourcePath) {
    return IMG_LoadTexture(renderer->sdlRenderer, resourcePath.c_str());
}
