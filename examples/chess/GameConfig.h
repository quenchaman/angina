#ifndef EXAMPLES_CHESS_GAMECONFIG_H_
#define EXAMPLES_CHESS_GAMECONFIG_H_

#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Color.h"

namespace GameConfig {

const Point BOARD_ORIGIN_POS = { 0, 75 };
const std::string GAME_TITLE = "Chess";
const Point BLACK_PIECES_CEMETERY = { 0, 0 };
const Point WHITE_PIECES_CEMETERY = { 0, 720 };
const int32_t SPACE_BETWEEN_GRAVES = 30;
const Dimensions WINDOW_DIM = { 800, 800 };
const Dimensions CELL_DIM = { 80, 80 };
const Dimensions BOARD_DIM = { 640, 640 };

const Point NEW_GAME_BTN_POS = { 300, 300 };
const Dimensions DEFAULT_BTN_DIM = { 200, 70 };
const Color DEFAULT_BTN_BACKGROUND_COLOR = Color::BLUE;
const Color DEFAULT_BTN_TEXT_COLOR = Color::RED;
const std::string NEW_GAME_BTN_TEXT = "PvP";
const std::string QUIT_GAME_BTN_TEXT = "Quit";
const Point QUIT_GAME_BTN_POS = { 670, 50 };
const Dimensions QUIT_GAME_BTN_DIM = { 100, 50 };
const int32_t BOARD_SIZE = 8;

const Point HUMAN_VS_COMPUTER_POS = { 300, 390 };
const std::string HUMAN_VS_COMPUTER_TEXT = "PvCPU";

const Point COMPUTER_VS_COMPUTER_POS = { 300, 480 };
const std::string COMPUTER_VS_COMPUTER_TEXT = "CPUvCPU";

const Point TITLE_POS = { 300, 100 };
const std::string TITLE_TEXT = "Chess";
const Dimensions TITLE_DIM = { 200, 100 };
}

#endif /* EXAMPLES_CHESS_GAMECONFIG_H_ */
