#ifndef PLATFORM_IDS_FORWARDIDGENERATOR_H_
#define PLATFORM_IDS_FORWARDIDGENERATOR_H_

#include "platform/ids/IdGenerator.h"

class ForwardIdGenerator: public IdGenerator {
public:
	ForwardIdGenerator();

	int32_t next();
};

#endif /* PLATFORM_IDS_FORWARDIDGENERATOR_H_ */
