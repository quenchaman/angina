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
	INITIALIZE_BOARD,
	WHITE,
    BLACK,
    HUMAN,
    COMPUTER,
    AVAILABLE_MOVES,
	SELECTED,
	CALCULATE_CAPTURES,
	CALCULATE_CHECK,
    CHECKMATE,
    STALEMATE,
    SWITCH_PLAYER,
    CONTINUE,
    COMPUTER_MOVE,
    HUMAN_MOVE,
    PUT_PIECE,
};



#endif /* CHESS_STATE_H_ */
