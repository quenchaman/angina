#ifndef EXAMPLES_TEST_TESTENGINE_H_
#define EXAMPLES_TEST_TESTENGINE_H_

#include <stack>

#include "enginev2/GameEngine.h"

struct Cell {
  int32_t row;
  int32_t col;
};

struct Texture;

class TestEngine : public GameEngine {
public:
	TestEngine();

	void onStart();
	void handleEvent();

	void samplePixel(int32_t x, int32_t y);
	void findPath(int32_t row, int32_t col, int32_t targetRow, int32_t targetCol);
private:
	Texture* txt;
	uint32_t* mPixels;
	int32_t mHeight;

	const int32_t cellsPerRow = 20;
	std::stack<Cell> path;
	bool visited[20][20];
	bool mazeGrid[20][20];
};

#endif /* EXAMPLES_TEST_TESTENGINE_H_ */
