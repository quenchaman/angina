#ifndef CORE_MATH_GEOMETRY_GEOMETRY_H_
#define CORE_MATH_GEOMETRY_GEOMETRY_H_

#include <utility>
#include <cstdint>

typedef std::pair<float, float> PointPair;
typedef std::pair<float, float> DimensionsPair;

namespace Geometry {
	PointPair calculateCenter(PointPair p, DimensionsPair dim);
	bool isInRect(PointPair origin, DimensionsPair dim, PointPair query);

	/* This is not quite geometry, but I am too focused on the game logic to create classes right now :*) */
	PointPair lerp(PointPair a, PointPair b, float step);
};

#endif /* CORE_MATH_GEOMETRY_GEOMETRY_H_ */
