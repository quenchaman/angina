#include "ChessMoveLog.h"

ChessMoveLog::ChessMoveLog() {}

void ChessMoveLog::addMove(const Move& move) {
	moves.push_back(move);
	notify(move);
}

std::vector<std::string> ChessMoveLog::getLogs() const {
	std::vector<std::string> logLines;

	for (const Move& move : moves) {
		std::stringstream ss;
		ss << move;
		logLines.push_back(ss.str());
	}

	return logLines;
}

void ChessMoveLog::subscribe(std::function<void(const Move&)> handler) {
    subscribers.push_back(handler);
}

void ChessMoveLog::notify(const Move& move) {
    for (auto& sub : subscribers) {
        sub(move);
    }
}
