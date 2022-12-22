#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<Texture> texture, const std::vector<Rectangle>& frames, float animationTime):
	texturePtr(texture),
	frames(frames),
	currentFrame(0),
	animationTime(animationTime) {}
