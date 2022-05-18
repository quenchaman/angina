#ifndef RESOURCES_RESOURCES_H_
#define RESOURCES_RESOURCES_H_

#include <string>
#include <iostream>

namespace Resources {
#ifndef NDEBUG
	const std::string prefix = "../resources/";
#endif
#ifdef NDEBUG
	const std::string prefix = "resources/";
#endif


	namespace Chess {
		const std::string chessPrefix = prefix + "chess/";

		const std::string board = chessPrefix + "Chess-Board.png";
		const std::string blackBishop = chessPrefix + "Bishop_B.png";
		const std::string blackKing = chessPrefix + "King_B.png";
		const std::string blackKnight = chessPrefix + "Knight_B.png";
		const std::string blackPawn = chessPrefix + "Pawn_B.png";
		const std::string blackQueen = chessPrefix + "Queen_B.png";
		const std::string blackRook = chessPrefix + "Rook_B.png";

		const std::string whiteBishop = chessPrefix + "Bishop_W.png";
		const std::string whiteKing = chessPrefix + "King_W.png";
		const std::string whiteKnight = chessPrefix + "Knight_W.png";
		const std::string whitePawn = chessPrefix + "Pawn_W.png";
		const std::string whiteQueen = chessPrefix + "Queen_W.png";
		const std::string whiteRook = chessPrefix + "Rook_W.png";
		const std::string startScreen2 = chessPrefix + "start_screen_2.png";
	}

	namespace Engine {
		const std::string enginePrefix = prefix + "engine/";
		const std::string montserratFont = enginePrefix + "montserrat/Montserrat-Bold.ttf";
		const std::string eye = enginePrefix + "eye.png";
		const std::string bg = enginePrefix + "sunnyday.png";
		const std::string human = enginePrefix + "human.png";
		const std::string balls = enginePrefix + "balls.png";
		const std::string windows = enginePrefix + "windows.png";
		const std::string sticky = enginePrefix + "stickfigure.png";
		const std::string arrow = enginePrefix + "arrow.png";
		const std::string maze101 = enginePrefix + "maze-101.png";
	}

	namespace MapBuilder {
		const std::string mapBuilderPrefix = prefix + "mapbuilder/";

		const std::string background = mapBuilderPrefix + "mbbg.jpg";
	}

	namespace TD {
		const std::string TDPrefix = prefix + "td/";

		const std::string background = TDPrefix + "startbg.png";

		const std::string TDTexturePrefix = TDPrefix + "textures/";

		const std::string grass = TDTexturePrefix + "grass.png";
	}


inline bool isResource(const std::string& str) {
	return str.find(prefix) != std::string::npos;
}
};

#endif /* RESOURCES_RESOURCES_H_ */
