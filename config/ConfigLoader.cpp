/*
 * ConfigLoader.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#include "ConfigLoader.h"

namespace ConfigLoader {
	ConfigData load() {
		std::ifstream fileStream("../config/config.json");
		std::stringstream stringBuffer;
		stringBuffer << fileStream.rdbuf();

		return {800, 800};
	}
}
