#ifndef EXAMPLES_TEST_TESTENGINE_H_
#define EXAMPLES_TEST_TESTENGINE_H_

#include "engine/Engine.h"

class TestEngine : public Engine {
public:
	TestEngine();

	void init();
	void update();
	void handleLeftMouseClick(Point);
	void handleBtnClick(int32_t idx);
};

#endif /* EXAMPLES_TEST_TESTENGINE_H_ */
