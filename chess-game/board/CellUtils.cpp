/*
 * CellUtils.cpp
 *
 *  Created on: Jan 21, 2022
 *      Author: ubuntu
 */

#include "CellUtils.h"

Point CellUtils::cellToPoint(Cell cell, Dimensions dim) {
	return { cell.col * dim.w, cell.row * dim.h };
}

Cell CellUtils::pointToCell(Point point, Dimensions dim) {
	return { point.y / dim.h, point.x / dim.w };
}
