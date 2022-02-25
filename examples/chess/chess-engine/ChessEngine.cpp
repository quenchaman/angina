#include "ChessEngine.h"

#include <cstdint>

ChessEngine::ChessEngine() {
	// TODO Auto-generated constructor stub

}

void ChessEngine::setBoard() {
	const int32_t blackPawnRow = 1;
	const int32_t whitePawnRow = 6;

	for (int32_t col = 0; col < BOARD_SIZE; col++) {
		Cell c = { blackPawnRow, col };

		board[c] = Piece { Rank::PAWN, Side::BLACK };
	}
}
