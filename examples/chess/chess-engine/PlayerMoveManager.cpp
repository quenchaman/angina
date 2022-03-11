#include "PlayerMoveManager.h"

#include "examples/chess/chess-engine/ChessBoard.h"

PlayerMoveManager::PlayerMoveManager(ChessBoard& chessBoard, PieceMoveGenerator& moveGen): board(chessBoard) {}
