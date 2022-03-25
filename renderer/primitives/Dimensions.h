#ifndef SDL_PRIMITIVES_DIMENSIONS_H_
#define SDL_PRIMITIVES_DIMENSIONS_H_

#include <cstdint>

struct Dimensions {
    Dimensions();
    Dimensions(int32_t width, int32_t height);

    int32_t w;
    int32_t h;

    static const Dimensions UNDEFINED;
};

#endif /* SDL_PRIMITIVES_DIMENSIONS_H_ */
