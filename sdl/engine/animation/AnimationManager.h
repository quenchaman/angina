/*
 * AnimationManager.h
 *
 *  Created on: Jan 4, 2022
 *      Author: ubuntu
 */

#ifndef SDL_ENGINE_ANIMATION_ANIMATIONMANAGER_H_
#define SDL_ENGINE_ANIMATION_ANIMATIONMANAGER_H_

#include <unordered_map>

#include "sdl/engine/animation/AnimationData.h"

typedef std::unordered_map<uint32_t, bool> AnimationStatus;
typedef std::unordered_map<uint32_t, AnimationData> AnimationDataStore;

class AnimationManager {
public:
	AnimationManager() = default;
	~AnimationManager() = default;

	/*
	 * Adds the animation and returns an ID, which can be attached to the Object or other class so we can apply animations on it.
	 */
	uint32_t registerAnimation(AnimationData data);

	/*
	 * Sets the animation for the Object associated with id to 'active', which means it will be processed on next frame.
	 */
	void startAnimation(uint32_t id);

	void stopAnimation(uint32_t id);

	/*
	 * Should we apply this animation on the current frame?
	 */
	bool isActive(uint32_t id);

	void removeAnimation(uint32_t id);
private:
	AnimationStatus _animationStatus;
	AnimationDataStore _store;

	/*
	 * This method will return an id which is not taken by any animation so far.
	 */
	uint32_t findNextAvailableId();
};

#endif /* SDL_ENGINE_ANIMATION_ANIMATIONMANAGER_H_ */
