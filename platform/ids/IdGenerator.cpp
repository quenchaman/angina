#include "IdGenerator.h"

IdGenerator::IdGenerator() :
        current(0) {
}

int32_t IdGenerator::next() {
    return current++;
}

