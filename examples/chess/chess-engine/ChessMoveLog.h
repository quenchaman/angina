#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVELOG_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVELOG_H_

#include <vector>
#include <string>
#include <sstream>

#include "examples/chess/chess-engine/Move.h"

class ChessMoveLog {
public:
	ChessMoveLog();

	void addMove(const Move&);

	std::vector<std::string> getLogs() const;
private:
	std::vector<Move> moves;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVELOG_H_ */
