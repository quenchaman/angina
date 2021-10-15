/*
 * SpaceKillz.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#ifndef SPACEKILLZ_H_
#define SPACEKILLZ_H_

#include "sdl/graphics/Engine.h"

class SpaceKillz : public Engine {
public:
	SpaceKillz();
	~SpaceKillz();
	void init();
	void executeGameLogic();
	void draw();
private:
	Surface* imageSurface;
};


#endif /* SPACEKILLZ_H_ */
