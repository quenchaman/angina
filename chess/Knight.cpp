//
// Created by ubuntu on 11/25/21.
//

#include "Knight.h"

Knight::Knight(int32_t _col, int32_t _row, Side _side, Image* _image) : Piece(_col, _row, Rank::KNIGHT, _side, _image) {

}

Knight::~Knight() {

}

std::vector<Cell> Knight::calculateMoves() {
    return std::vector<Cell>();
}
