#ifndef ENGINEV2_COMPONENTS_PRIMITIVESCOMPONENT_H_
#define ENGINEV2_COMPONENTS_PRIMITIVESCOMPONENT_H_

#include <cstdint>
#include <vector>
#include <unordered_map>

#include "enginev2/graphics/sdl/primitives/Rectangle.h"

struct GameEngine;

template <typename T>
class PrimitivesComponent {
public:
	friend class GameEngine;
protected:
	PrimitivesComponent(int32_t maxEntries) {
		data.reserve(maxEntries);
	}

	void addViewPort(const Rectangle& rect) {
		viewPorts[data.size()] = rect;
	}

	std::vector<T> data;
	std::unordered_map<int32_t, Rectangle> viewPorts;
};

#endif /* ENGINEV2_COMPONENTS_PRIMITIVESCOMPONENT_H_ */
