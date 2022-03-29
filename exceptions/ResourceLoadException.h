#ifndef EXCEPTIONS_RESOURCELOADEXCEPTION_H_
#define EXCEPTIONS_RESOURCELOADEXCEPTION_H_

#include <string>

#include "BaseException.h"

class ResourceLoadException: public BaseException {
public:
	ResourceLoadException(std::string msg);
};

#endif /* EXCEPTIONS_RESOURCELOADEXCEPTION_H_ */
