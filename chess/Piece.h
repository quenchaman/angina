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

	Piece(int32_t id, int32_t col, int32_t row, Rank rank, Side side, Texture* texture);

	virtual ~Piece() = 0;

	int32_t getCol();

	int32_t getRow();

	Rank getRank();

	Side getSide();

	Image* getImage();

	virtual std::vector<Cell> calculateMoves() = 0;
	void draw(Renderer& renderer);

private:
	int32_t id;
	int32_t col;
	int32_t row;
	Rank rank;
	Side side;
	Image* image;
};


#endif /* CHESS_PIECE_H_ */
