#include "ChessMoveLog.h"

ChessMoveLog::ChessMoveLog() {
}

void ChessMoveLog::addMove(const Move &move) {
	moves.push_back(move);
	notify(move);
}

void ChessMoveLog::subscribe(std::function<void(const Move&)> handler) {
	subscribers.push_back(handler);
}

void ChessMoveLog::notify(const Move &move) {
	for (auto &sub : subscribers) {
		sub(move);
	}
}
