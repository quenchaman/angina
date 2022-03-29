#include "ReverseIdGenerator.h"

ReverseIdGenerator::ReverseIdGenerator() {}

int32_t ReverseIdGenerator::next() {
	return current--;
}
