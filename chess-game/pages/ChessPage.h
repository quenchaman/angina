/*
 * ChessPage.h
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_PAGES_CHESSPAGE_H_
#define CHESS_GAME_PAGES_CHESSPAGE_H_

#include "sdl/engine/page/Page.h"

struct Renderer;
struct Board;

class ChessPage : public Page {
public:
	ChessPage(Renderer& renderer);
	~ChessPage() = default;

	void draw();
	void onPageLoad();
	void onPageUnload();
private:
	Board* board;
};

#endif /* CHESS_GAME_PAGES_CHESSPAGE_H_ */
