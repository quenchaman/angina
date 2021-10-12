/*
 * BaseException.h
 *
 *  Created on: Oct 12, 2021
 *      Author: ubuntu
 */

#ifndef EXCEPTIONS_BASEEXCEPTION_H_
#define EXCEPTIONS_BASEEXCEPTION_H_

#include <stdexcept>
#include <iostream>

class BaseException : public std::runtime_error {
public:
	BaseException(std::string msg);

	friend std::ostream& operator<<(std::ostream& os, const std::runtime_error& ex);
};


#endif /* EXCEPTIONS_BASEEXCEPTION_H_ */
