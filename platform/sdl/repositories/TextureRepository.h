#ifndef PLATFORM_SDL_REPOSITORIES_TEXTUREREPOSITORY_H_
#define PLATFORM_SDL_REPOSITORIES_TEXTUREREPOSITORY_H_

#include <string>

#include "platform/sdl/repositories/TextureCache.h"

struct SurfaceRepository;
struct Texture;
struct Renderer;

class TextureRepository {
public:
    TextureRepository(SurfaceRepository&, Renderer&);

    Texture& get(const std::string& resourcePath);
private:
    TextureCache textureCache;
    SurfaceRepository& surfaceRepo;
    Renderer& renderer;
};

#endif /* PLATFORM_SDL_REPOSITORIES_TEXTUREREPOSITORY_H_ */
