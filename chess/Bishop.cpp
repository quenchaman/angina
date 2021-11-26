//
// Created by ubuntu on 11/25/21.
//

#include "Bishop.h"

Bishop::Bishop(int32_t _id, int32_t _col, int32_t _row, Side _side, Texture *_texture): Piece(_id, _col, _row, Rank::BISHOP, _side, _texture) {

}

Bishop::~Bishop() {

}

std::vector<Cell> Bishop::calculateMoves() {
    return std::vector<Cell>();
}
