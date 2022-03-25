#ifndef EXCEPTIONS_WINDOWINITEXCEPTION_H_
#define EXCEPTIONS_WINDOWINITEXCEPTION_H_

#include <string>

#include "BaseException.h"

class WindowInitException: public BaseException {
public:
    WindowInitException(std::string msg);
};

#endif /* EXCEPTIONS_WINDOWINITEXCEPTION_H_ */
