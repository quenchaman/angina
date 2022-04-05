#include "TextureRepository.h"

#include "platform/sdl/repositories/SurfaceRepository.h"
#include "platform/sdl/primitives/Texture.h"
#include "renderer/Renderer.h"

TextureRepository::TextureRepository(SurfaceRepository& surfaceRepository, Renderer& r):
    surfaceRepo(surfaceRepository), renderer(r) {}

Texture& TextureRepository::get(const std::string& resourcePath) {
    Texture* texture = nullptr;

    if (textureCache.exists(resourcePath)) {
        texture = &textureCache.get(resourcePath);
    } else {
        texture = &renderer.from(surfaceRepo.get(resourcePath));
        textureCache.add(resourcePath, *texture);
    }

    return *texture;
}
