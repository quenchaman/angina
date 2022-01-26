/*
 * ScoredMove.cpp
 *
 *  Created on: Jan 26, 2022
 *      Author: ubuntu
 */

#include "ScoredMove.h"

ScoredMove::ScoredMove(Cell destinationIn, Piece* pieceIn, double scoreIn): destination(destinationIn), piece(pieceIn), score(scoreIn) {
}

std::ostream& operator<<(std::ostream& os, const ScoredMove& move) {
	return os << "Destination: " << move.destination << "\nPiece: " << move.piece << "\nScore: " << move.score;
}
