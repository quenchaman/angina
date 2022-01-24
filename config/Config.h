/*
 * Config.h
 *
 *  Created on: Oct 13, 2021
 *      Author: ubuntu
 */

#ifndef CONFIG_CONFIG_H_
#define CONFIG_CONFIG_H_

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
}


#endif /* CONFIG_CONFIG_H_ */
