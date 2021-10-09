/*
 * ResourceLoadException.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: ubuntu
 */

#include "ResourceLoadException.h"

ResourceLoadException::ResourceLoadException(std::string msg):
	std::runtime_error(("Could not load resource. " + msg).c_str()) {}
