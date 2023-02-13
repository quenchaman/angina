#include "Sprite.h"

#include "enginev2/graphics/models/Point.h"
#include "enginev2/graphics/models/Dimensions.h"

Sprite::Sprite(const Point& pos, std::shared_ptr<Texture> texture, const std::vector<Rectangle>& frames, uint64_t animationTime):
	pos(pos),
	atlas(texture),
	frames(frames),
	currentFrame(0),
	animationTime(animationTime) {}

Sprite::Sprite(const Point& pos, SDL_Texture* sdlTex, const std::vector<Rectangle>& frames, uint64_t animationTime):
	Sprite(pos, std::make_shared<Texture>(sdlTex), frames, animationTime) {}

Sprite::Sprite(const Point& pos, std::shared_ptr<Texture> texture, uint32_t frameCount, uint64_t animationTime) :
	Sprite(pos, texture, std::vector<Rectangle>(), animationTime)
{
	this->frames = generateFrames(frameCount);
}

Sprite::Sprite(const Point& pos, SDL_Texture* texture, uint32_t frameCount, uint64_t animationTime):
	Sprite(pos, std::make_shared<Texture>(texture), frameCount, animationTime) {}

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
