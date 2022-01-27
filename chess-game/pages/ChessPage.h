/*
 * ChessPage.h
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_PAGES_CHESSPAGE_H_
#define CHESS_GAME_PAGES_CHESSPAGE_H_

#include "sdl/engine/page/Page.h"
#include "chess-game/pieces/Side.h"
#include "chess-game/pieces/Rank.h"
#include "chess-game/enums/ChessAssets.h"
#include "chess-game/board/Cell.h"

struct Renderer;
struct Board;

class ChessPage : public Page {
public:
	ChessPage(Renderer& renderer);
	~ChessPage();

	void draw();
	void onPageLoad();
	void onPageUnload();
	void createPiece(ChessAssets asset, std::string resource, Cell cell, Rank rank, Side side);
	Board* getBoard();
private:
	Board* board;

	void drawDeadPieces();
};

#endif /* CHESS_GAME_PAGES_CHESSPAGE_H_ */
