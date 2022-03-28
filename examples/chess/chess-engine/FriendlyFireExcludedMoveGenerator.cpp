#include "FriendlyFireExcludedMoveGenerator.h"

#include "examples/chess/chess-engine/BoardBoundsPieceMoveGenerator.h"
#include "examples/chess/chess-engine/ChessBoard.h"

FriendlyFireExcludedMoveGenerator::FriendlyFireExcludedMoveGenerator(
        ChessBoard &chessBoard, BoardBoundsPieceMoveGenerator &generator) :
        board(chessBoard), moveGen(generator) {
}

CellUnorderedSet FriendlyFireExcludedMoveGenerator::generatePieceMoves(
        const Cell &pieceCell) const {
    CellUnorderedSet friendlyFireExcludedMoves;

    Piece piece = board.getPieceOnCell(pieceCell);

    CellUnorderedSet boundedMoves = moveGen.generatePieceMoves(piece,
            pieceCell);

    for (auto const &cell : boundedMoves) {
        if (board.isValidTarget(cell, piece.side)) {
        	std::cout << "Inserting a cell " << cell << std::endl;
            friendlyFireExcludedMoves.insert(cell);
        }
    }

    return friendlyFireExcludedMoves;
}
