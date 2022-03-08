#include "ChessEngine.h"

ChessEngine::ChessEngine() {
	board.setBoard();
}

ChessEngine::~ChessEngine() {
}

void ChessEngine::selectPiece(const Cell& source) {
	selectedCell = source;
}

void ChessEngine::movePiece(const Cell& destination) {
	board.makeMove(selectedCell, destination);
	notify(selectedCell, destination);
}

bool ChessEngine::isCellSelected() const {
	return selectedCell != Cell::UNDEFINED;
}

const CellToPieceLookup& ChessEngine::getPieces() const {
	return board.getPiecePositions();
}

void ChessEngine::subscribe(MoveEventCallback callback) {
	subscribers.push_back(callback);
}

void ChessEngine::notify(const Cell& source, const Cell& destination) const {
	for (auto& subscriber : subscribers) {
		subscriber(source, destination);
	}
}

Move ChessEngine::getAIMove() {
	// Here we will assume AI is with black pieces.
	std::vector<Move> allMoves = board.calculateAllAvailableMoves(Side::BLACK);

	std::cout << "Size of all moves is: " << allMoves.size() << std::endl;

	if (allMoves.empty()) {
		// TODO: here we might have check or draw or something.
	}

	sort(allMoves.begin(), allMoves.end(), [](const Move& lMove, const Move& rMove) {
		return rMove.score - lMove.score;
	});

	return allMoves[0];
}
