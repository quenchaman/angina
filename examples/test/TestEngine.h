#ifndef EXAMPLES_TEST_TESTENGINE_H_
#define EXAMPLES_TEST_TESTENGINE_H_

#include "enginev2/GameEngine.h"

class Texture;

class TestEngine : public GameEngine {
public:
	TestEngine();

	void onStart();
	void onUpdate();
	void handleEvent();

private:
	Texture* txt;
	int32_t maxLevels;
};

#endif /* EXAMPLES_TEST_TESTENGINE_H_ */
