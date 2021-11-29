//
// Created by ubuntu on 11/25/21.
//

#include "Rook.h"

Rook::Rook(int32_t _col, int32_t _row, Side _side, Image *_image): Piece(_col, _row, Rank::ROOK, _side, _image) {

}

Rook::~Rook() {

}

std::vector<Cell> Rook::calculateMoves() {
    return std::vector<Cell>();
}
