//
// Created by ubuntu on 11/25/21.
//

#ifndef ANGINA_KING_H
#define ANGINA_KING_H


#include "Piece.h"

class King : public Piece {
public:
    King(int32_t _id, int32_t _col, int32_t _row, Side _side, Texture* _texture);

    ~King();

    std::vector<Cell> calculateMoves();
};


#endif //ANGINA_KING_H
