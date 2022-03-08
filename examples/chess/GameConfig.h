#ifndef EXAMPLES_CHESS_GAMECONFIG_H_
#define EXAMPLES_CHESS_GAMECONFIG_H_

#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"

namespace GameConfig {
	const Point BOARD_ORIGIN_POS = {0, 75};
	const std::string GAME_TITLE = "Chess";
	const Point BLACK_PIECES_CEMETERY = {0, 0};
	const Point WHITE_PIECES_CEMETERY = {0, 720};
	const int32_t SPACE_BETWEEN_GRAVES = 30;
	const Dimensions WINDOW_DIM = {800, 800};
	const Dimensions CELL_DIM = { 80, 80 };
	const Dimensions BOARD_DIM = { 640, 640 };

	const Point NEW_GAME_BTN_POS = { 300, 300 };
	const Dimensions NEW_GAME_BTN_DIM = { 200, 70 };
	const Color NEW_GAME_BTN_BACKGROUND_COLOR = Color::BLUE;
	const Color NEW_GAME_BTN_TEXT_COLOR = Color::RED;
	const std::string NEW_GAME_BTN_TEXT = "Start game";
}

#endif /* EXAMPLES_CHESS_GAMECONFIG_H_ */
