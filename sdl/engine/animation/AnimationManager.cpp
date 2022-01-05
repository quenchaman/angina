/*
 * AnimationManager.cpp
 *
 *  Created on: Jan 4, 2022
 *      Author: ubuntu
 */

#include "AnimationManager.h"

#include <limits>


uint32_t AnimationManager::registerAnimation(AnimationData data) {
	uint32_t id = findNextAvailableId();

	_store[id] = data;
	_animationStatus[id] = false;

	return id;
}


void AnimationManager::startAnimation(uint32_t id) {
	_animationStatus[id] = true;
}

void AnimationManager::stopAnimation(uint32_t id) {
	_animationStatus[id] = false;
}

bool AnimationManager::isActive(uint32_t id) {
	return _animationStatus[id];
}

void AnimationManager::removeAnimation(uint32_t id) {
	_animationStatus.erase(id);
	_store.erase(id);
}

uint32_t AnimationManager::findNextAvailableId() {
	const uint32_t MAX_POSSIBLE_ID = std::numeric_limits<uint32_t>::max();

	for (uint32_t id = 0; id <= MAX_POSSIBLE_ID; id++) {
		if (_store.find(id) != _store.end()) {
			return id;
		}
	}

	return 0; // If we ever run out of animations the engine will break...
}
