#ifndef EXAMPLES_CHESS_CHESS_ENGINE_PIECETOOBJECTTRANSLATOR_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_PIECETOOBJECTTRANSLATOR_H_

#include <unordered_map>
#include <string>

#include "examples/chess/chess-engine/Piece.h"

typedef std::unordered_map<Piece, std::string, Piece::HashFunction> PieceToResourcePath;

class PieceToObjectTranslator {
public:
	PieceToObjectTranslator();

	PieceToResourcePath pieceToResource;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_PIECETOOBJECTTRANSLATOR_H_ */
