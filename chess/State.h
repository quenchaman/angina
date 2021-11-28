/*
 * State.h
 *
 *  Created on: Nov 26, 2021
 *      Author: ubuntu
 */

#ifndef CHESS_STATE_H_
#define CHESS_STATE_H_

enum State {
    WELCOME_SCREEN,
	INIT,
	USER,
	SELECTED,
	CHECK_CAPTURES,
	COMPUTER,
	CHECK_CHECK,
    CHECKMATE,
    STALEMATE,
    CAPTURER
};



#endif /* CHESS_STATE_H_ */
