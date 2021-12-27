/*
 * Resources.h
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#ifndef RESOURCES_RESOURCES_H_
#define RESOURCES_RESOURCES_H_

#include <string>

namespace Resources {
	const std::string prefix = "../chess/";

    const std::string whiteWins = prefix + "white_wins.png";
    const std::string blackWins = prefix + "black_wins.png";
    const std::string startScreen = prefix + "start_screen.png";
	const std::string board = prefix + "Chess-Board.png";
	const std::string blackBishop = prefix + "Bishop_B.png";
	const std::string blackKing = prefix + "King_B.png";
	const std::string blackKnight = prefix + "Knight_B.png";
	const std::string blackPawn = prefix + "Pawn_B.png";
	const std::string blackQueen = prefix + "Queen_B.png";
	const std::string blackRook = prefix + "Rook_B.png";

	const std::string whiteBishop = prefix + "Bishop_W.png";
	const std::string whiteKing = prefix + "King_W.png";
	const std::string whiteKnight = prefix + "Knight_W.png";
	const std::string whitePawn = prefix + "Pawn_W.png";
	const std::string whiteQueen = prefix + "Queen_W.png";
	const std::string whiteRook = prefix + "Rook_W.png";
    const std::string startScreen2 = prefix + "start_screen_2.png";
    const std::string newGameButton = prefix + "button_new_game.png";
    const std::string continueGameButton = prefix + "button_continue_game.png";
    const std::string quitGameButton = prefix + "button_quit_game.png";
    const std::string saveGameButton = prefix + "button_save_game.png";


    const std::string montserratFont = prefix + "Montserrat-Bold.ttf";
};


#endif /* RESOURCES_RESOURCES_H_ */
