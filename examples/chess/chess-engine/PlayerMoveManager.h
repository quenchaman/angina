#ifndef EXAMPLES_CHESS_CHESS_ENGINE_PLAYERMOVEMANAGER_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_PLAYERMOVEMANAGER_H_

struct ChessBoard;
struct PieceMoveGenerator;

class PlayerMoveManager {
public:
	PlayerMoveManager(ChessBoard&, PieceMoveGenerator&);

private:
	ChessBoard& board;
	PieceMoveGenerator& moveGen;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_PLAYERMOVEMANAGER_H_ */
