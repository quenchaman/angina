#include "Sprite.h"

#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/commons/primitives/Dimensions.h"

Sprite::Sprite(std::shared_ptr<Texture> texture, const std::vector<Rectangle>& frames, uint64_t animationTime):
	atlas(texture),
	frames(frames),
	currentFrame(0),
	animationTime(animationTime) {}

Sprite::Sprite(SDL_Texture* sdlTex, const std::vector<Rectangle>& frames, uint64_t animationTime):
	Sprite(std::make_shared<Texture>(sdlTex), frames, animationTime) {}

Sprite::Sprite(SDL_Texture* texture, uint32_t frameCount, uint64_t animationTime):
	Sprite(std::make_shared<Texture>(texture), {}, animationTime) {
	
	this->frames = generateFrames(frameCount);
}

std::vector<Rectangle> Sprite::generateFrames(uint32_t frameCount)
{
	auto dim = atlas->getDimensions();
	uint32_t frameWidth = dim.w / frameCount;
	uint32_t currentWidth = 0;
	std::vector<Rectangle> frames;

	for (int32_t frameN = 0; frameN < frameCount; frameN++) {
		frames.push_back(Rectangle(Point(currentWidth, 0), Dimensions(frameWidth, dim.h)));
		currentWidth += frameWidth;
	}

	return frames;
}
