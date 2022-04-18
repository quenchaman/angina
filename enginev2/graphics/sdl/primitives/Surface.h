#ifndef SDL_COMPONENTS_SURFACE_H_
#define SDL_COMPONENTS_SURFACE_H_

#include <string>

struct SDL_Surface;

/**
 * Wrapper around SDL_Surface and manages the life-cycle of the surface.
 */
class Surface {
public:
	Surface(const std::string& surfaceAssetPath);
	~Surface();

	SDL_Surface& getSurface();
private:
	SDL_Surface* surface;
};

#endif /* SDL_COMPONENTS_SURFACE_H_ */
