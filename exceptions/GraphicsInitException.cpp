/*
 * GraphicsInitException.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#include "GraphicsInitException.h"

GraphicsInitException::GraphicsInitException(std::string msg):
	std::runtime_error(("Could not initialize graphics - " + msg).c_str()) {}

std::ostream& operator<<(std::ostream& os, const GraphicsInitException& ex) {
	os << ex.what();
	return os;
}
