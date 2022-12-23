#ifndef IDGENERATOR_H_
#define IDGENERATOR_H_

#include <stdint.h>

typedef uint16_t ID;

class IdGenerator {
public:
	IdGenerator();
	virtual ~IdGenerator() = default;

	virtual ID next() = 0;
protected:
	ID current;
};

#endif /* IDGENERATOR_H_ */
