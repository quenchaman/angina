/*
 * ResourceLoadException.h
 *
 *  Created on: Oct 9, 2021
 *      Author: ubuntu
 */

#ifndef EXCEPTIONS_RESOURCELOADEXCEPTION_H_
#define EXCEPTIONS_RESOURCELOADEXCEPTION_H_

#include <stdexcept>
#include <string>
#include <iostream>

class ResourceLoadException : public std::runtime_error {
public:
	ResourceLoadException(std::string msg);

	friend std::ostream& operator<<(std::ostream& os, const ResourceLoadException& ex);
};


#endif /* EXCEPTIONS_RESOURCELOADEXCEPTION_H_ */
