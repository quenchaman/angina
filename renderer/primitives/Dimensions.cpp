#include "Dimensions.h"

Dimensions::Dimensions() :
        w(0), h(0) {
}
Dimensions::Dimensions(int32_t width, int32_t height) :
        w(width), h(height) {
}

const Dimensions Dimensions::UNDEFINED(0, 0);
