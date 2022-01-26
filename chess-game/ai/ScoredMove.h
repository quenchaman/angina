/*
 * ScoredMove.h
 *
 *  Created on: Jan 26, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_AI_SCOREDMOVE_H_
#define CHESS_GAME_AI_SCOREDMOVE_H_

#include "chess-game/board/Cell.h"

struct Piece;

struct ScoredMove {
	ScoredMove(Cell destination, Piece* piece, double score);

	Cell destination;
	Piece* piece;
	double score;

	struct HighestScoreComparator {
		inline bool operator() (const ScoredMove& first, const ScoredMove& second) {
			return first.score >= second.score;
		}
	};
};

#endif /* CHESS_GAME_AI_SCOREDMOVE_H_ */
