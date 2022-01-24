/*
 * CellUtils.cpp
 *
 *  Created on: Jan 21, 2022
 *      Author: ubuntu
 */

#include "CellUtils.h"

Point CellUtils::cellToPoint(Cell cell, Dimensions cellDimensions, Point offset) {
	return Point{ cell.col * cellDimensions.w, cell.row * cellDimensions.h } + offset;
}

Cell CellUtils::pointToCell(Point point, Dimensions cellDimensions, Point offset) {
	Point cellOriginPoint = point - offset;
	return { cellOriginPoint.y / cellDimensions.h, cellOriginPoint.x / cellDimensions.w };
}
