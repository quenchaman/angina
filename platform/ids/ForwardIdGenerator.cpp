#include "ForwardIdGenerator.h"

ForwardIdGenerator::ForwardIdGenerator() {}

int32_t ForwardIdGenerator::next() {
	return current++;
}
