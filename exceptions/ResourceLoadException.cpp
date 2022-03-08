#include "ResourceLoadException.h"

ResourceLoadException::ResourceLoadException(std::string msg):
	BaseException("Could not load resource. " + msg) {}
