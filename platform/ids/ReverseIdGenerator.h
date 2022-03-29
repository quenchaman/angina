#ifndef PLATFORM_IDS_REVERSEIDGENERATOR_H_
#define PLATFORM_IDS_REVERSEIDGENERATOR_H_

#include "platform/ids/IdGenerator.h"

class ReverseIdGenerator: public IdGenerator {
public:
	ReverseIdGenerator();

	int32_t next();
};

#endif /* PLATFORM_IDS_REVERSEIDGENERATOR_H_ */
