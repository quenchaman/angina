#ifndef ENGINEV2_COMPONENTS_PRIMITIVESCOMPONENT_H_
#define ENGINEV2_COMPONENTS_PRIMITIVESCOMPONENT_H_

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <iostream>

#include "enginev2/graphics/sdl/primitives/Rectangle.h"

struct GameEngine;

template <typename T>
class PrimitivesComponent {
public:
	friend class GameEngine;

	void init(uint16_t maxElements = 16) {
		data.reserve(maxElements);
	}

	void add(const T& el) {
		data.push_back(el);
	}
protected:
	std::vector<T> data;
};

#endif /* ENGINEV2_COMPONENTS_PRIMITIVESCOMPONENT_H_ */
