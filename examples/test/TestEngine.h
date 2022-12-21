#ifndef EXAMPLES_TEST_TESTENGINE_H_
#define EXAMPLES_TEST_TESTENGINE_H_

#include "enginev2/GameEngine.h"

class Texture;

class TestEngine : public GameEngine {
public:
	TestEngine();

	void onStart();
	void handleEvent();

	void drawSerpinski(const Line& l1, const Line& l2, int32_t level);
private:
	Texture* txt;
	int32_t maxLevels;
};

#endif /* EXAMPLES_TEST_TESTENGINE_H_ */
