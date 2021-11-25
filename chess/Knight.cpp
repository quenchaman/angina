//
// Created by ubuntu on 11/25/21.
//

#include "Knight.h"

Knight::Knight(int32_t _id, int32_t _col, int32_t _row, Side _side, Texture* _texture) : Piece(_id, _col, _row, Rank::KNIGHT, _side, _texture) {

}

Knight::~Knight() {

}

std::vector<Cell> Knight::calculateMoves() {
    return std::vector<Cell>();
}
