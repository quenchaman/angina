//
// Created by ubuntu on 11/25/21.
//

#include "Queen.h"

Queen::Queen(int32_t _col, int32_t _row, Side _side, Image *_image): Piece(_col, _row, Rank::QUEEN, _side, _image) {

}

Queen::~Queen() {

}

std::vector<Cell> Queen::calculateMoves(std::map<Cell, Piece*> boardPieces) {
    return std::vector<Cell>();
}
