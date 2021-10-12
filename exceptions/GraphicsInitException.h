/*
 * GraphicsInitException.h
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#ifndef EXCEPTIONS_GRAPHICSINITEXCEPTION_H_
#define EXCEPTIONS_GRAPHICSINITEXCEPTION_H_

#include "BaseException.h"

class GraphicsInitException : public BaseException {
public:
	GraphicsInitException(std::string msg);
};

#endif /* EXCEPTIONS_GRAPHICSINITEXCEPTION_H_ */
