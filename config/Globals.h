/*
 * Globals.h
 *
 *  Created on: Oct 30, 2021
 *      Author: ubuntu
 */

#ifndef CONFIG_GLOBALS_H_
#define CONFIG_GLOBALS_H_

#include "ConfigData.h"
#include "ConfigLoader.h"

namespace Globals {
	static ConfigData config = ConfigLoader::load();
}

#endif /* CONFIG_GLOBALS_H_ */
