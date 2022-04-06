#ifndef EXAMPLES_CHESS_CHESS_ENGINE_MOVELOGSCREEN_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_MOVELOGSCREEN_H_

#include <deque>
#include <string>
#include <stdint.h>

#include "../../../engine/screen/Screen.h"
#include "renderer/primitives/Color.h"
#include "renderer/primitives/Dimensions.h"

struct GraphicsFactory;
struct Font;

class MoveLogWidget: public Screen {
public:
	MoveLogWidget(Point, GraphicsFactory&, Font&, uint32_t sizeCap = 10);

	void add(std::string, int32_t textWidth, Color = Color::GREEN);
private:
	GraphicsFactory &textFactory;
	Font &font;
	uint32_t sizeCap;
	int32_t yOffset;

	std::deque<int32_t> textLineIds;

	void removeLastLine();
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_MOVELOGSCREEN_H_ */
