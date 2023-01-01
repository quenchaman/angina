#include "SpriteAnimator.h"

#include <chrono>

#include "platform/time/TimeUtils.h"

ID SpriteAnimator::add(const Sprite& sprite)
{
	auto id = idGen.next();
	Sprite& addedSprite = PrimitivesComponent::add(sprite);
	
	animatedSprites[id] = AnimatedSprite { &addedSprite, false, 0 };

	return id;
}

void SpriteAnimator::activate(ID id)
{
	if (!animatedSprites[id].isActive) {
		animatedSprites[id].isActive = true;
		animatedSprites[id].timeSinceAnimationStart = TimeUtils::timestamp();
	}
}

void SpriteAnimator::deactivate(ID id)
{
	animatedSprites[id].isActive = false;
	animatedSprites[id].sprite->currentFrame = 0;
}

void SpriteAnimator::remove(ID id)
{
	animatedSprites.erase(id);
}

void SpriteAnimator::update()
{
	for (auto& [id, sprite] : animatedSprites) {
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
	auto progressInAnim = (deltaMs % (animSprite.sprite->animationTime - 1)) /
		static_cast<float>(animSprite.sprite->animationTime);

	animSprite.sprite->currentFrame = animSprite.sprite->frames.size() * progressInAnim;
}
