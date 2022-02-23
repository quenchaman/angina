#ifndef SDL_COMPONENTS_SURFACE_H_
#define SDL_COMPONENTS_SURFACE_H_

struct SDL_Surface;

class Surface {
public:
	Surface(SDL_Surface* surface);
	~Surface();

	Surface(const Surface& other) = delete;
	Surface& operator=(const Surface& other) = delete;
	Surface(Surface&& other) = delete;
	Surface& operator=(Surface&& other) = delete;

	SDL_Surface* getSurface();
private:
	SDL_Surface* surface;
};


#endif /* SDL_COMPONENTS_SURFACE_H_ */
