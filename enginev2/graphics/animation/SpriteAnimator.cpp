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
	sprites[id].timestamp = TimeUtils::timestamp();
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
	auto now = TimeUtils::timestamp();
	auto deltaMs = now - animSprite.timestamp;
	auto progressInAnim = (deltaMs % animSprite.sprite.animationTime) /
		static_cast<float>(animSprite.sprite.animationTime);

	animSprite.sprite.currentFrame = (animSprite.sprite.frames.size() - 1) * progressInAnim;
}
