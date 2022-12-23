#include "ForwardIdGenerator.h"

ForwardIdGenerator::ForwardIdGenerator() {
}

ID ForwardIdGenerator::next() {
	return current++;
}
