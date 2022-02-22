#ifndef CORE_MATH_GEOMETRY_GEOMETRY_H_
#define CORE_MATH_GEOMETRY_GEOMETRY_H_

#include <utility>
#include <cstdint>

typedef std::pair<int32_t, int32_t> PointPair;
typedef std::pair<uint32_t, uint32_t> DimensionsPair;

namespace Geometry {
PointPair calculateCenter(PointPair p, DimensionsPair dim);
};

#endif /* CORE_MATH_GEOMETRY_GEOMETRY_H_ */
