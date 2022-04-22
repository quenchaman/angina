#include "AnimationComponent.h"

#include "enginev2/graphics/sdl/primitives/Texture.h"

AnimationComponent::AnimationComponent(Texture& txt, int32_t frames): tx(txt), frameCount(frames), index(0) {}

void AnimationComponent::addFrame(const Rectangle& rect) {
	if (index >= frameCount - 1) return;

	frames.push_back(rect);
}

void AnimationComponent::update() {
	tx.setClip(frames[index++]);

	if (index >= frameCount - 1) {
		index = 0;
	}
}
