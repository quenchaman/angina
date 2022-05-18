#ifndef EXAMPLES_TEST_TESTENGINE_H_
#define EXAMPLES_TEST_TESTENGINE_H_

#include "enginev2/GameEngine.h"

struct Texture;

class TestEngine : public GameEngine {
public:
	TestEngine();

	void onStart();
	void handleEvent();
private:
	Texture* txt;
};

#endif /* EXAMPLES_TEST_TESTENGINE_H_ */
