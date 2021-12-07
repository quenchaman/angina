//
// Created by ubuntu on 12/7/21.
//

#ifndef CHESS_CONSTANTS_H
#define CHESS_CONSTANTS_H

#include "resources/Resources.h"

namespace Constants {
    static const std::vector<std::string> paths = {
            Resources::board,
            Resources::blackBishop,
            Resources::blackKing,
            Resources::blackKnight,
            Resources::blackPawn,
            Resources::blackQueen,
            Resources::blackRook,
            Resources::whiteBishop,
            Resources::whiteKing,
            Resources::whiteKnight,
            Resources::whitePawn,
            Resources::whiteQueen,
            Resources::whiteRook,
            Resources::startScreen,
            Resources::whiteWins,
            Resources::blackWins,
            Resources::startScreen2,
            Resources::newGameButton,
            Resources::continueGameButton,
            Resources::quitGameButton,
            Resources::saveGameButton
    };

    static std::unordered_map<Rank, std::string> rankEnumToStringMap = {
            {Rank::ROOK, "Rook"},
            {Rank::KING, "King"},
            {Rank::PAWN, "Pawn"},
            {Rank::KNIGHT, "Knight"},
            {Rank::QUEEN, "Queen"},
            {Rank::BISHOP, "Bishop"}
    };

    static std::unordered_map<int32_t, std::string> colToLetterMap = {
            {0, "A"},
            {1, "B"},
            {2, "C"},
            {3, "D"},
            {4, "E"},
            {5, "F"},
            {6, "G"},
            {7, "H"}
    };

    static const int32_t logTextX = 100;
    static const int32_t logTextY = 660;
    static const int32_t logFontSize = 28;
    static const int32_t turnDuration = 60;
    static const int32_t maxLogLines = 5;
}

#endif //CHESS_CONSTANTS_H
