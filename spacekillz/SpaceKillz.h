/*
 * SpaceKillz.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#ifndef SPACEKILLZ_H_
#define SPACEKILLZ_H_

#include "sdl/graphics/Engine.h"

#include <vector>

class SpaceKillz : public Engine {
public:
	SpaceKillz();
	~SpaceKillz();
	void init();
	void executeGameLogic();
	void draw();

	void handleUpArrowKey();
	void handleDownArrowKey();
	void handleLeftArrowKey();
	void handleRightArrowKey();
	void handleOtherKey();
private:
	Texture* image;
	std::vector<Surface*> images;
};


#endif /* SPACEKILLZ_H_ */
