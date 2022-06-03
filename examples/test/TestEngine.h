#ifndef EXAMPLES_TEST_TESTENGINE_H_
#define EXAMPLES_TEST_TESTENGINE_H_

#include "enginev2/GameEngine.h"
#include "enginev2/graphics/commons/primitives/Point.h"

struct Texture;

class TestEngine : public GameEngine {
public:
	TestEngine();

	void onStart();
	void handleEvent();
private:
	static const int32_t pointCount = 1000;
	Point points[pointCount];

	Point findRectOrigin(int32_t x, int32_t y) const;
	int32_t distanceBetweenPoints(const Point& p1, const Point& p2) const;
	Point findClosestPoint(const Point& p) const;
	void findClosestForAllPoints();
};

#endif /* EXAMPLES_TEST_TESTENGINE_H_ */
