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

		nlohmann::json fileConfigAsJson = nlohmann::json::parse(stringBuffer.str());

		ConfigData config;
		config.screenWidth = fileConfigAsJson["screenWidth"];
		config.screenHeight = fileConfigAsJson["screenHeight"];

		return config;
	}
}
