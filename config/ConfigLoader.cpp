/*
 * ConfigLoader.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#include "ConfigLoader.h"

namespace ConfigLoader {
	ConfigData load() {
		return {Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, Config::FRAME_RATE};
	}
}
