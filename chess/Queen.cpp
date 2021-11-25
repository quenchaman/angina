//
// Created by ubuntu on 11/25/21.
//

#include "Queen.h"

Queen::Queen(int32_t _id, int32_t _col, int32_t _row, Side _side, Texture *_texture): Piece(_id, _col, _row, Rank::QUEEN, _side, _texture) {

}

Queen::~Queen() {

}

std::vector<Cell> Queen::calculateMoves() {
    return std::vector<Cell>();
}
