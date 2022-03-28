#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVELOG_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVELOG_H_

#include <vector>
#include <string>
#include <functional>
#include <sstream>

#include "examples/chess/chess-engine/Move.h"

class ChessMoveLog {
public:
	ChessMoveLog();

	void addMove(const Move&);

	std::vector<std::string> getLogs() const;

	void subscribe(std::function<void(const Move&)>);
private:
	std::vector<Move> moves;
	std::vector<std::function<void(const Move&)>> subscribers;

	void notify(const Move&);
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVELOG_H_ */
