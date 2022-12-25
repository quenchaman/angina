#include "SpriteAnimator.h"

#include <chrono>

#include "platform/time/TimeUtils.h"

ID SpriteAnimator::add(const Sprite& sprite)
{
	auto id = idGen.next();
	sprites[id] = AnimatedSprite { sprite, false, 0 };
	
	return id;
}

void SpriteAnimator::activate(ID id)
{
	sprites[id].isActive = true;
	sprites[id].timeSinceAnimationStart = TimeUtils::timestamp();
}

void SpriteAnimator::remove(ID id)
{
	sprites.erase(id);
}

void SpriteAnimator::update()
{
	for (auto& [id, sprite] : sprites) {
		if (sprite.isActive) {
			process(sprite);
		}
	}
}

void SpriteAnimator::process(AnimatedSprite& animSprite)
{
	auto now = TimeUtils::timestamp(); // Maybe it will be better to use the main loop clock to
	// find how much time has passed
	auto deltaMs = now - animSprite.timeSinceAnimationStart;
	auto progressInAnim = (deltaMs % (animSprite.sprite.animationTime - 1)) /
		static_cast<float>(animSprite.sprite.animationTime);

	animSprite.sprite.currentFrame = animSprite.sprite.frames.size() * progressInAnim;
}
