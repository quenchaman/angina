/*
 * ResourceLoadException.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: valeri
 */

#include "ResourceLoadException.h"

ResourceLoadException::ResourceLoadException(std::string msg):
	BaseException("Could not load resource. " + msg) {}
