#ifndef ENGINEV2_COMPONENTS_PRIMITIVESCOMPONENT_H_
#define ENGINEV2_COMPONENTS_PRIMITIVESCOMPONENT_H_

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <iostream>

#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "ID.h"

class GameEngine;

template <typename T>
class PrimitivesComponent {
public:
	friend class GameEngine;

	void init(uint16_t maxElements = 16) {
		data.reserve(maxElements);
	}

	T& add(const T& el) {
		data.push_back(el);
		return data[data.size() - 1];
	}

	T& get(ID id) {
		for (int32_t i = 0; i < data.size(); i++) {
			if (data[i].id == id) {
				return data[i];
			}
		}
	}

	void remove(ID id) {
		for (auto it = data.begin(); it != data.end();) {
			if (it->id == id) {
				it = data.erase(it);
			}
			else {
				it++;
			}
		}
	}
protected:
	std::vector<T> data;
};

#endif /* ENGINEV2_COMPONENTS_PRIMITIVESCOMPONENT_H_ */
