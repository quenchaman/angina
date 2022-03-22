#ifndef IDGENERATOR_H_
#define IDGENERATOR_H_

#include <stdint.h>

class IdGenerator {
public:
	IdGenerator();

	int32_t next();
private:
	int32_t current;
};

#endif /* IDGENERATOR_H_ */
