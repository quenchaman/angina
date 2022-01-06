/*
 * Dimensions.cpp
 *
 *  Created on: Jan 6, 2022
 *      Author: ubuntu
 */
#include "Dimensions.h"

Dimensions::Dimensions(int32_t width, int32_t height): w(width), h(height) {}

const Dimensions Dimensions::UNDEFINED(0, 0);
