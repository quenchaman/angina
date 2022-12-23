#ifndef ENGINEV2_GRAPHICS_ANIMATION_SPRITE_ANIMATOR_H
#define ENGINEV2_GRAPHICS_ANIMATION_SPRITE_ANIMATOR_H

#include <memory>
#include <unordered_map>
#include <cstdint>

#include "enginev2/graphics/sdl/primitives/Texture.h"
#include "enginev2/graphics/animation/Sprite.h"
#include "platform/ids/ForwardIdGenerator.h"

static struct AnimatedSprite {
	AnimatedSprite() = default;

	Sprite sprite;
	uint64_t timestamp; // TODO: Consider switching this to chrono::duration
	bool isActive;
};

class SpriteAnimator {
public:
	ID add(const Sprite&);
	void activate(ID);
	void remove(ID);
	void update();
private:
	ForwardIdGenerator idGen;
	std::unordered_map<ID, AnimatedSprite> sprites;
	
	void process(AnimatedSprite&);
};

#endif // !ENGINEV2_GRAPHICS_ANIMATION_SPRITE_ANIMATOR_H
