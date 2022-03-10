#include "ChessEngine.h"

ChessEngine::ChessEngine(): moveGen(PieceMoveGenerator(board)) {
	board.setInitialPieceFormation();
}

ChessEngine::~ChessEngine() {
}

Side ChessEngine::switchSide() {
	return currentSide = currentSide == Side::WHITE ? Side::BLACK : Side::WHITE;
}

void ChessEngine::selectPiece(const Cell& source) {
	selectedCell = source;
}

bool ChessEngine::movePiece(const Cell& destination) {
	if (board.tryMakeMove(selectedCell, destination)) {
		notify(selectedCell, destination);
		resetSelection();

		return true;
	}

	resetSelection();
	return false;
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
	std::vector<Move> allMoves = calculateAllAvailableMoves(Side::BLACK);

	std::cout << "Size of all moves is: " << allMoves.size() << std::endl;

	if (allMoves.empty()) {
		// TODO: here we might have check or draw or something.
	}

	sort(allMoves.begin(), allMoves.end(), [](const Move& lMove, const Move& rMove) {
		return rMove.score - lMove.score;
	});

	return allMoves[0];
}

void ChessEngine::resetSelection() {
	selectedCell = Cell::UNDEFINED;
}

bool ChessEngine::isValidPieceMove(const Cell& source, const Cell& destination) const {
	CellUnorderedSet allowedMoves = moveGen.generatePieceMoves(board.getPieceOnCell(source), source);

	return allowedMoves.find(destination) != allowedMoves.end();
}

std::vector<Move> ChessEngine::generateValidPieceMoves(const Piece& piece, const Cell& cell) const {
	std::vector<Move> moves;
	CellUnorderedSet currentPieceMoves = moveGen.generatePieceMoves(piece, cell);

	for (const Cell& dest : currentPieceMoves) {
		if (board.isPossibleMove(cell, dest)) {

			double score = scoreMove(dest);
			moves.push_back(Move{cell, dest, score});
		}
	}

	return moves;
}

std::vector<Move> ChessEngine::calculateAllAvailableMoves(Side side) const {
	std::vector<Move> allMoves;

//	In chess, if a "node" is considered to be a legal position,
//	the average branching factor has been said to be about 35,[1][2]
//	and a statistical analysis of over 2.5 million games revealed an average of 31.[3]
//	This means that, on average, a player has about 31 to 35 legal moves at their disposal at each turn.
//	By comparison, the average branching factor for the game Go is 250.[1]
	allMoves.reserve(31);

	for (auto const& [cell, piece] : board.getPiecePositions()) {
		if (piece.side == side) {
			std::vector<Move> currentValidPieceMoves = generateValidPieceMoves(piece, cell);

			allMoves.insert(allMoves.end(), currentValidPieceMoves.begin(), currentValidPieceMoves.end());
		}
	}

	return allMoves;
}

double ChessEngine::scoreMove(const Cell& destination) const {
	if (!board.isEmptyCell(destination)) {
		return 1;
	}

	return 0;
}

