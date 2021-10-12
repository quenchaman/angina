/*
 * GraphicsInitException.h
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#ifndef EXCEPTIONS_GRAPHICSINITEXCEPTION_H_
#define EXCEPTIONS_GRAPHICSINITEXCEPTION_H_

#include <stdexcept>
#include <iostream>

class GraphicsInitException : public std::runtime_error {
public:
	GraphicsInitException(std::string msg);

	friend std::ostream& operator<<(std::ostream& os, const GraphicsInitException& ex);
};

#endif /* EXCEPTIONS_GRAPHICSINITEXCEPTION_H_ */
