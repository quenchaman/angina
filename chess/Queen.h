//
// Created by ubuntu on 11/25/21.
//

#ifndef ANGINA_QUEEN_H
#define ANGINA_QUEEN_H


#include "Piece.h"

class Queen : public Piece {
public:
    Queen(int32_t _id, int32_t _col, int32_t _row, Side _side, Texture* _texture);

    ~Queen();

    std::vector<Cell> calculateMoves();
};


#endif //ANGINA_QUEEN_H
