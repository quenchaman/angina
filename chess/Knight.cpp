//
// Created by ubuntu on 11/25/21.
//

#include "Knight.h"

Knight::Knight(int32_t _col, int32_t _row, Side _side, Image* _image) : Piece(_col, _row, Rank::KNIGHT, _side, _image) {

}

Knight::~Knight() {

}

std::vector<Cell> Knight::calculateMoves(std::vector<Piece*> boardPieces) {
    std::vector<Cell> moves;

    moves.push_back({ piecePos.col - 2, piecePos.row - 1 });
	moves.push_back({ piecePos.col - 1, piecePos.row - 2 });
	moves.push_back({ piecePos.col + 1, piecePos.row - 2 });
	moves.push_back({ piecePos.col + 2, piecePos.row - 1 });
	moves.push_back({ piecePos.col + 2, piecePos.row + 1 });
	moves.push_back({ piecePos.col + 1, piecePos.row + 2 });
	moves.push_back({ piecePos.col - 1, piecePos.row + 2 });
	moves.push_back({ piecePos.col - 2, piecePos.row + 1 });

	return moves;
}
