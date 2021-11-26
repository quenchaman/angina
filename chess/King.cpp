//
// Created by ubuntu on 11/25/21.
//

#include "King.h"

King::King(int32_t _id, int32_t _col, int32_t _row, Side _side, Texture *_texture): Piece(_id, _col, _row, Rank::KING, _side, _texture) {

}

King::~King() {

}

std::vector<Cell> King::calculateMoves() {
    return std::vector<Cell>();
}
