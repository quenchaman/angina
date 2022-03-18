#include "ChessMoveManager.h"

#include "examples/chess/chess-engine/FriendlyFireExcludedMoveGenerator.h"

ChessMoveManager::ChessMoveManager(ChessBoard& chessBoard, FriendlyFireExcludedMoveGenerator& generator): board(chessBoard), moveGen(generator) {}

bool ChessMoveManager::movePiece(const Cell& source, const Cell& destination) {
	CellUnorderedSet moves = moveGen.generatePieceMoves(source);
	bool isOkMove = moves.find(destination) != moves.end();

	if (!isOkMove) { return false; }

	board.movePiece(source, destination);

	return true;
}

Move ChessMoveManager::getAIMove(Side side) {
	// Here we will assume AI is with black pieces.
	std::vector<Move> allMoves = calculateAllAvailableMoves(side);

	std::cout << "Size of all moves is: " << allMoves.size() << std::endl;

	if (allMoves.empty()) {
		// TODO: here we might have check or draw or something.
	}

	sort(allMoves.begin(), allMoves.end(), [](const Move& lMove, const Move& rMove) {
		return rMove.score - lMove.score;
	});

	// We can return an undefined move if we don't have moves.
	return allMoves[0];
}

std::vector<Move> ChessMoveManager::scorePieceMoves(const Cell& cell) const {
	std::vector<Move> moves;
	CellUnorderedSet currentPieceMoves = moveGen.generatePieceMoves(cell);

	for (const Cell& dest : currentPieceMoves) {
		moves.push_back(Move{cell, dest, scoreMove(dest)});
	}

	return moves;
}

std::vector<Move> ChessMoveManager::calculateAllAvailableMoves(Side side) {
	std::vector<Move> allMoves;

  // In chess, if a "node" is considered to be a legal position,
  // the average branching factor has been said to be about 35,[1][2]
  // and a statistical analysis of over 2.5 million games revealed an average of 31.[3]
  // This means that, on average, a player has about 31 to 35 legal moves at their disposal at each turn.
  // By comparison, the average branching factor for the game Go is 250.[1]
	allMoves.reserve(31);

	for (auto const& [cell, piece] : board.getPiecePositions()) {
		if (piece.side == side) {
			std::vector<Move> currentValidPieceMoves = scorePieceMoves(cell);

			allMoves.insert(allMoves.end(), currentValidPieceMoves.begin(), currentValidPieceMoves.end());
		}
	}

	return allMoves;
}

double ChessMoveManager::scoreMove(const Cell& destination) const {
	if (!board.isEmptyCell(destination)) {
		return 1;
	}

	return 0;
}

