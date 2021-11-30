//
// Created by ubuntu on 11/25/21.
//

#ifndef ANGINA_KNIGHT_H
#define ANGINA_KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(int32_t _col, int32_t _row, Side _side, Image* _image);

    ~Knight();

    std::vector<Cell> calculateMoves(std::map<Cell, Piece*> boardPieces);
};


#endif //ANGINA_KNIGHT_H
