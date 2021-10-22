/*
 * ConfigLoader.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef CONFIG_CONFIGLOADER_H_
#define CONFIG_CONFIGLOADER_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include "nlohmann/json.hpp"

#include "ConfigData.h"

namespace ConfigLoader {
	ConfigData load();
}


#endif /* CONFIG_CONFIGLOADER_H_ */
