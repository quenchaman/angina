/*
 * WindowInitException.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: ubuntu
 */

#include "WindowInitException.h"

WindowInitException::WindowInitException(std::string msg):
	BaseException("Could not initialize window. " + msg) {}
