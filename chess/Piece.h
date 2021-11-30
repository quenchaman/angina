/*
 * Piece.h
 *
 *  Created on: Nov 19, 2021
 *      Author: ubuntu
 */

#ifndef CHESS_PIECE_H_
#define CHESS_PIECE_H_

#include <cstdint>
#include <vector>

#include "Side.h"
#include "Rank.h"
#include "Cell.h"
#include "sdl/graphics/Renderer.h"
#include "sdl/graphics/Image.h"

class Piece {
public:
	static const int32_t PIECE_WIDTH = 80;
	static const int32_t PIECE_HEIGHT = 80;

	Piece(int32_t col, int32_t row, Rank rank, Side side, Image* image);
    virtual ~Piece() {};

    void move(Cell cell);

	int32_t getCol();

	int32_t getRow();

	Rank getRank();

	Side getSide();

	Image* getImage();

	Cell getCell();

	virtual std::vector<Cell> calculateMoves(std::map<Cell, Piece*> boardPieces) = 0;
	void draw(Renderer& renderer);

private:
	int32_t col;
	int32_t row;
	Rank rank;
	Side side;
protected:
	Image* image;
};


#endif /* CHESS_PIECE_H_ */
