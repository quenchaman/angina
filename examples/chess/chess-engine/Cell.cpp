#include "Cell.h"

Cell::Cell(int32_t _row, int32_t _col): row(_row), col(_col) {

}

bool Cell::operator==(const Cell& cell) const {
	return row == cell.row && col == cell.col;
}

bool Cell::operator!=(const Cell& cell) const {
	return !(*this == cell);
}

const Cell Cell::UNDEFINED(10000, 10000);

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
	return os << "Row: " << cell.row << "; " << "Col: " << cell.col;
}
