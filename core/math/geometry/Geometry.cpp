#include "Geometry.h"

PointPair Geometry::calculateCenter(PointPair p, DimensionsPair dim) {
	uint32_t wMid = dim.first / 2;
	uint32_t hMid = dim.second / 2;

	return std::make_pair(p.first + wMid, p.second + hMid);
}
