#ifndef CORE_MATH_GEOMETRY_GEOMETRY_H_
#define CORE_MATH_GEOMETRY_GEOMETRY_H_

#include <utility>
#include <cstdint>

typedef std::pair<int32_t, int32_t> PointPair;
typedef std::pair<int32_t, int32_t> DimensionsPair;

namespace Geometry {
	PointPair calculateCenter(PointPair p, DimensionsPair dim);
	bool isInRect(PointPair origin, DimensionsPair dim, PointPair query);

	/* This is not quite geometry, but I am too focused on the game logic to create classes right now :*) */
	PointPair lerp(PointPair a, PointPair b, int32_t step);
};

#endif /* CORE_MATH_GEOMETRY_GEOMETRY_H_ */
