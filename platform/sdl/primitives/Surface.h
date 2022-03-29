#ifndef SDL_COMPONENTS_SURFACE_H_
#define SDL_COMPONENTS_SURFACE_H_

struct SDL_Surface;

class Surface {
public:
	Surface(SDL_Surface*);
	~Surface();

	Surface(const Surface&) = delete;
	Surface& operator=(const Surface&) = delete;
	Surface(Surface&&) = delete;
	Surface& operator=(Surface&&) = delete;

	SDL_Surface* getSurface();
private:
	SDL_Surface *surface;
};

#endif /* SDL_COMPONENTS_SURFACE_H_ */
