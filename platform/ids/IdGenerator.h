#ifndef IDGENERATOR_H_
#define IDGENERATOR_H_

#include <stdint.h>

class IdGenerator {
public:
    IdGenerator();
    virtual ~IdGenerator() = default;

    virtual int32_t next() = 0;
protected:
    int32_t current;
};

#endif /* IDGENERATOR_H_ */
