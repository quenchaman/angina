/*
 * GraphicsInitException.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#include "GraphicsInitException.h"

GraphicsInitException::GraphicsInitException(std::string msg) :
		BaseException(("Could not initialize graphics - " + msg).c_str()) {
}
