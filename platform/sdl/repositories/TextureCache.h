#ifndef RENDERER_REPOSITORIES_TEXTUREREPOSITORY_H_
#define RENDERER_REPOSITORIES_TEXTUREREPOSITORY_H_

#include "Cache.h"
#include "platform/sdl/primitives/Texture.h"

/*
 * Cache for GPU 2D primitive.
 *
 */
class TextureCache : public Cache<Texture> {
};

#endif /* RENDERER_REPOSITORIES_TEXTUREREPOSITORY_H_ */
