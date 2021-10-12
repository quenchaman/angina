/*
 * ResourceLoadException.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: valeri
 */

#include "ResourceLoadException.h"

ResourceLoadException::ResourceLoadException(std::string msg):
	std::runtime_error(("Could not load resource. " + msg).c_str()) {}

std::ostream& operator<<(std::ostream& os, const ResourceLoadException& ex) {
	os << ex.what();
	return os;
}
