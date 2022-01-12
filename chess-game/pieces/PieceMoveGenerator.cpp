/*
 * PieceMoveGenerator.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: ubuntu
 */

#include "PieceMoveGenerator.h"

std::vector<Move> PieceMoveGenerator::generateKnightMoves(Cell knightPosition) {
	std::vector<Move> m;

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
