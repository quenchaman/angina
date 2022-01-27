/*
 * Config.h
 *
 *  Created on: Oct 13, 2021
 *      Author: ubuntu
 */

#ifndef CONFIG_CONFIG_H_
#define CONFIG_CONFIG_H_

#include <string>
#include <cstdint>

#include "sdl/primitives/Point.h"
#include "sdl/primitives/Dimensions.h"

namespace Config {
	const int32_t SCREEN_WIDTH = 640;
	const int32_t SCREEN_HEIGHT = 480;
	const int32_t FRAME_RATE = 20;
	const Point NEW_GAME_BTN_POS = {300, 350};
	const Point BOARD_ORIGIN_POS = {0, 75};
	const Dimensions WINDOW_DIM = {800, 800};
	const std::string GAME_TITLE = "Chess";
	const Point BLACK_PIECES_CEMETERY = {0, 0};
	const Point WHITE_PIECES_CEMETERY = {0, 720};
	const int32_t SPACE_BETWEEN_GRAVES = 30;
}


#endif /* CONFIG_CONFIG_H_ */
