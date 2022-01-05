/*
 * AnimationData.h
 *
 *  Created on: Jan 4, 2022
 *      Author: ubuntu
 */

#ifndef SDL_ENGINE_ANIMATION_ANIMATIONDATA_H_
#define SDL_ENGINE_ANIMATION_ANIMATIONDATA_H_

#include <cstdint>

struct AnimationData {
	double animationDegreeStep; // 15.0 degrees
	int64_t interval; // 30 (ms)
};


#endif /* SDL_ENGINE_ANIMATION_ANIMATIONDATA_H_ */
