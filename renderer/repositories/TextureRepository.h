#ifndef RENDERER_REPOSITORIES_TEXTUREREPOSITORY_H_
#define RENDERER_REPOSITORIES_TEXTUREREPOSITORY_H_

#include "renderer/repositories/Repository.h"
#include "platform/sdl/primitives/Texture.h"

/*
 * Cache for GPU 2D primitive.
 *
 */
class TextureRepository : public Repository<Texture> {
};

#endif /* RENDERER_REPOSITORIES_TEXTUREREPOSITORY_H_ */
