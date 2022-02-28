#include "PieceMoveGenerator.h"

std::vector<Move> PieceMoveGenerator::generateKnightMoves(Cell& knightPosition) {
	std::vector<Move> m;
	m.reserve(8);

	m.push_back(Move{knightPosition, Cell{knightPosition.row - 2, knightPosition.col + 1}});
	m.push_back(Move{knightPosition, Cell{knightPosition.row - 2, knightPosition.col - 1}});

	m.push_back(Move{knightPosition, Cell{knightPosition.row + 2, knightPosition.col + 1}});
	m.push_back(Move{knightPosition, Cell{knightPosition.row + 2, knightPosition.col - 1}});

	m.push_back(Move{knightPosition, Cell{knightPosition.row - 1, knightPosition.col - 2}});
	m.push_back(Move{knightPosition, Cell{knightPosition.row + 1, knightPosition.col - 2}});

	m.push_back(Move{knightPosition, Cell{knightPosition.row - 1, knightPosition.col + 2}});
	m.push_back(Move{knightPosition, Cell{knightPosition.row + 1, knightPosition.col + 2}});

	return m;
}



// TODO: Test performance with a unordered_set
std::vector<Move> PieceMoveGenerator::generatePieceMoves(Rank& rank, Cell& source) {
	std::vector<Move> moves;

	switch (rank) {
		case Rank::KNIGHT:
			moves = PieceMoveGenerator::generateKnightMoves(source);
			break;
		default:
			break;
	}

	return moves;
}
