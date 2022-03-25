#ifndef CHESS_GAME_AI_SCOREDMOVE_H_
#define CHESS_GAME_AI_SCOREDMOVE_H_

#include <iostream>

#include "examples/chess/chess-engine/Cell.h"

struct Piece;

struct ScoredMove {
    ScoredMove(Cell destination, double score);

    Cell destination;
    double score;

    struct HighestScoreComparator {
        inline bool operator()(const ScoredMove &first,
                const ScoredMove &second) {
            return first.score >= second.score;
        }
    };

    friend std::ostream& operator<<(std::ostream &os, const ScoredMove &move);
};

#endif /* CHESS_GAME_AI_SCOREDMOVE_H_ */
