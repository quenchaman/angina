/*
 * SpaceKillz.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#ifndef SPACEKILLZ_H_
#define SPACEKILLZ_H_

#include "sdl/graphics/Engine.h"
#include "sdl/graphics/Texture.h"
#include "sdl/components/Transformer.h"

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
	std::vector<Texture*> textures;
};


#endif /* SPACEKILLZ_H_ */
