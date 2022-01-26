#ifndef CHESS_GAME_UTILS_VECTORSHUFFLER_H_
#define CHESS_GAME_UTILS_VECTORSHUFFLER_H_

#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

struct Piece;

class VectorShuffler {
public:
	template <typename T>
	void shuffle(std::vector<T>& c) const {
		std::random_shuffle(c.begin(), c.end());
	}
};

#endif /* CHESS_GAME_UTILS_VECTORSHUFFLER_H_ */
