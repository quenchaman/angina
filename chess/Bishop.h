//
// Created by ubuntu on 11/25/21.
//

#ifndef ANGINA_BISHOP_H
#define ANGINA_BISHOP_H


#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int32_t _col, int32_t _row, Side _side, Image* _image);

    ~Bishop();

    std::vector<Cell> calculateMoves(std::map<Cell, Piece*> boardPieces);

    void calculateMoves(std::map<Cell, Piece*> boardPieces, Cell currentCell);
private:
    std::vector<Cell> moves;
};


#endif //ANGINA_BISHOP_H
