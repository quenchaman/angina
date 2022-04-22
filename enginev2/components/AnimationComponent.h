#ifndef ENGINEV2_COMPONENTS_ANIMATIONCOMPONENT_H_
#define ENGINEV2_COMPONENTS_ANIMATIONCOMPONENT_H_

#include <cstdint>
#include <vector>

#include "enginev2/graphics/sdl/primitives/Rectangle.h"

struct Texture;

class AnimationComponent {
public:
	AnimationComponent(Texture&, int32_t frames);

	void addFrame(const Rectangle&);
	void update();
private:
	Texture& tx;
	std::vector<Rectangle> frames;
	int32_t frameCount;
	int32_t index;
};

#endif /* ENGINEV2_COMPONENTS_ANIMATIONCOMPONENT_H_ */
