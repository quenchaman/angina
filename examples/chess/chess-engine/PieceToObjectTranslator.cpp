#include "PieceToObjectTranslator.h"

#include "resources/Resources.h"

PieceToObjectTranslator::PieceToObjectTranslator() {
	pieceToResource[Piece::WHITE_PAWN] = Resources::whitePawn;
	pieceToResource[Piece::WHITE_ROOK] = Resources::whiteRook;
	pieceToResource[Piece::WHITE_KNIGHT] = Resources::whiteKnight;
	pieceToResource[Piece::WHITE_BISHOP] = Resources::whiteBishop;
	pieceToResource[Piece::WHITE_QUEEN] = Resources::whiteQueen;
	pieceToResource[Piece::WHITE_KING] = Resources::whiteKing;

	pieceToResource[Piece::BLACK_PAWN] = Resources::blackPawn;
	pieceToResource[Piece::BLACK_ROOK] = Resources::blackRook;
	pieceToResource[Piece::BLACK_KNIGHT] = Resources::blackKnight;
	pieceToResource[Piece::BLACK_BISHOP] = Resources::blackBishop;
	pieceToResource[Piece::BLACK_QUEEN] = Resources::blackQueen;
	pieceToResource[Piece::BLACK_KING] = Resources::blackKing;
}

PieceToObjectTranslator::~PieceToObjectTranslator() {
	// TODO Auto-generated destructor stub
}

