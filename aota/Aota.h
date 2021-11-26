/*
 * SpaceKillz.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#ifndef AOTA_H_
#define AOTA_H_

#include "sdl/graphics/Engine.h"
#include "sdl/graphics/Texture.h"
#include "sdl/components/Transformer.h"
#include "sdl/graphics/Image.h"

#include <SDL.h>

#include <vector>
#include <string>
#include <iostream>

class Aota : public Engine {
public:
	Aota();
	~Aota();
	void init();
	void executeGameLogic();
	void draw();

	void handleUpArrowKey();
	void handleDownArrowKey();
	void handleLeftArrowKey();
	void handleRightArrowKey();
	void handleOtherKey();
private:
	Image* gameImage;
	std::vector<Image*> gameImages;
};


#endif /* AOTA_H_ */
