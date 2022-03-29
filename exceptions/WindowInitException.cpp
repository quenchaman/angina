#include "WindowInitException.h"

WindowInitException::WindowInitException(std::string msg) :
		BaseException("Could not initialize window. " + msg) {
}
