#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<Texture> texture, const std::vector<Rectangle>& frames, uint64_t animationTime):
	atlas(texture),
	frames(frames),
	currentFrame(0),
	animationTime(animationTime) {}

Sprite::Sprite(SDL_Texture* sdlTex, const std::vector<Rectangle>& frames, uint64_t animationTime):
	Sprite(std::make_shared<Texture>(sdlTex), frames, animationTime) {}
