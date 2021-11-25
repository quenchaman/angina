//
// Created by ubuntu on 11/25/21.
//

#ifndef ANGINA_ROOK_H
#define ANGINA_ROOK_H


#include "Piece.h"

class Rook : public Piece {
public:
    Rook(int32_t _id, int32_t _col, int32_t _row, Side _side, Texture* _texture);

    ~Rook();

    std::vector<Cell> calculateMoves();
};


#endif //ANGINA_ROOK_H
