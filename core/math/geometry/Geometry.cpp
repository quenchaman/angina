#include "Geometry.h"

PointPair Geometry::calculateCenter(PointPair p, DimensionsPair dim) {
	int32_t wMid = dim.first / 2;
	int32_t hMid = dim.second / 2;

	return std::make_pair(p.first + wMid, p.second + hMid);
}

bool Geometry::isInRect(PointPair origin, DimensionsPair dim, PointPair query) {
	return query.first >= origin.first
			&& query.first <= (origin.first + dim.first)
			&& query.second >= origin.second
			&& query.second <= origin.second + dim.second;
}

PointPair Geometry::lerp(PointPair a, PointPair b, int32_t step) {
	int32_t x = a.first + step;
	int32_t y = (a.second * (b.first - x) + b.second * (x - a.first)) / (b.first - a.first);

	return std::make_pair(x, y);
}
