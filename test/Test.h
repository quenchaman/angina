#ifndef TEST_TEST_H_
#define TEST_TEST_H_

#include <iostream>

#include "engine/Engine.h"

struct Text;

class Test : public Engine {
public:
	Test();
	~Test() override;

	void init() override;

	void update() override;

	void handleLeftMouseClick(Point point) override;

	void handleBtnClick(int32_t idx) override;
private:
	int privateNumber = 42;

	void callbackFunc();
};

#endif /* TEST_TEST_H_ */
