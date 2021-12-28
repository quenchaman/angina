/*
 * Surface.h
 *
 *  Created on: Oct 13, 2021
 *      Author: ubuntu
 */

#ifndef SDL_COMPONENTS_SURFACE_H_
#define SDL_COMPONENTS_SURFACE_H_

struct SDL_Surface;
struct SDL_PixelFormat;
struct SDL_Surface;

class Surface {
public:
	Surface(SDL_Surface* surface);
	~Surface();

	SDL_Surface* getSurface();
private:
	SDL_Surface* _surface;
};


#endif /* SDL_COMPONENTS_SURFACE_H_ */
