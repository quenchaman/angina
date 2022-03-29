#include "ScoredMove.h"

ScoredMove::ScoredMove(Cell destinationIn, double scoreIn) :
		destination(destinationIn), score(scoreIn) {
}

std::ostream& operator<<(std::ostream &os, const ScoredMove &move) {
	return os << "Destination: " << move.destination << "\nScore: " << move.score;
}
