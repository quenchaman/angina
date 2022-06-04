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
	static const int32_t pointCount = 64;
	Point points[pointCount];

	std::vector<Point> outlineConvex();
};

#endif /* EXAMPLES_TEST_TESTENGINE_H_ */
