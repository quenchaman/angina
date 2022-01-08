/*
 * Piece.cpp
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#include "Piece.h"

Piece::Piece(Object& _object, Cell _cell, Side _side, Rank _rank): object(_object), cell(_cell), side(_side), rank(_rank), hasMoved(false) {}
