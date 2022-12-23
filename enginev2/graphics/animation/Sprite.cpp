#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<Texture> texture, const std::vector<Rectangle>& frames, uint64_t animationTime):
	texturePtr(texture),
	frames(frames),
	currentFrame(0),
	animationTime(animationTime) {}
