#ifndef PLATFORM_SDL_REPOSITORIES_SURFACEREPOSITORY_H_
#define PLATFORM_SDL_REPOSITORIES_SURFACEREPOSITORY_H_

#include <string>

#include "platform/sdl/repositories/SurfaceCache.h"
#include "platform/sdl/primitives/Font.h"

#include "renderer/primitives/Color.h"

struct Surface;

/*
 * A cache on surfaces and textures. If the surface/texture is not loaded yet from disk it loads them, in the case of images.
 * For text it checks whether the specific string has been loaded already.
 * Note: Surfaces are not exposed from API, because we are not using CPU primitives in general.
 */
class SurfaceRepository {
public:
	SurfaceRepository();
	Surface& get(const std::string& resourcePath);
private:
	SurfaceCache surfaceCache;

	/* These below are hardcoded in the constructor initialiser list for simplicity */
	Font textFont;
	Color textColor;
};

#endif /* PLATFORM_SDL_REPOSITORIES_SURFACEREPOSITORY_H_ */
