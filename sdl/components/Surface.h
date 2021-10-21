/*
 * Surface.h
 *
 *  Created on: Oct 13, 2021
 *      Author: ubuntu
 */

#ifndef SDL_COMPONENTS_SURFACE_H_
#define SDL_COMPONENTS_SURFACE_H_

#include "SDL.h"

class Surface {
public:
	Surface(SDL_Surface* surface);
	~Surface();

	void paint(const Surface& other);
	SDL_PixelFormat* getFormat();
	SDL_Surface* getSurface();
private:
	SDL_Surface* _surface;
};


#endif /* SDL_COMPONENTS_SURFACE_H_ */
