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

	void onPageLoad();
private:
	Board* board;

	void drawDeadPieces();
};

#endif /* CHESS_GAME_PAGES_CHESSPAGE_H_ */
