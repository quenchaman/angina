/*
 * Chess.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: ubuntu
 */

#include "Chess.h"
#include "King.h"

void Chess::init() {
    loadGameResources(paths);

    board = resources[Resources::board];
}

void Chess::draw() {
	board->draw(*renderer);

    for (Piece* piece : activePieces) {
        piece->draw(*renderer);
    }
    for (Piece* piece : passivePieces) {
        piece->draw(*renderer);
    }
}

void Chess::executeGameLogic() {
    if (currentState == State::INITIALIZE_BOARD) {
        setPiecesOnBoard();
        currentState = State::WHITE;
    }
}

void Chess::handleLeftMouseClick() {
	int32_t x, y;
	SDL_GetMouseState(&x, &y);
}

Chess::Chess() : Engine("Chess") {
    currentState = State::INITIALIZE_BOARD;
    isWhiteHuman = true; // Change this in the future.
    currentSide = Side::White;
}

void Chess::setPiecesOnBoard() {
    for (int32_t colIdx = 0; colIdx < 8; colIdx++) {
        activePieces.push_back(new Pawn(colIdx, 6, Side::White, resources[Resources::whitePawn]));
        passivePieces.push_back(new Pawn(colIdx, 1, Side::Black, resources[Resources::blackPawn]));
    }

    activePieces.push_back(new Rook(0, 7, Side::White, resources[Resources::whiteRook]));
    activePieces.push_back(new Knight(1, 7, Side::White, resources[Resources::whiteKnight]));
    activePieces.push_back(new Bishop(2, 7, Side::White, resources[Resources::whiteBishop]));
    activePieces.push_back(new King(4, 7, Side::White, resources[Resources::whiteKing]));
    activePieces.push_back(new Bishop(5, 7, Side::White, resources[Resources::whiteBishop]));
    activePieces.push_back(new Knight(6, 7, Side::White, resources[Resources::whiteKnight]));
    activePieces.push_back(new Rook(7, 7, Side::White, resources[Resources::whiteRook]));

    passivePieces.push_back(new Rook(0, 0, Side::Black, resources[Resources::blackRook]));
    passivePieces.push_back(new Knight(1, 0, Side::Black, resources[Resources::blackKnight]));
    passivePieces.push_back(new Bishop(2, 0, Side::Black, resources[Resources::blackBishop]));
    passivePieces.push_back(new Bishop(5, 0, Side::Black, resources[Resources::blackBishop]));
    passivePieces.push_back(new Knight(6, 0, Side::Black, resources[Resources::blackKnight]));
    passivePieces.push_back(new Rook(7, 0, Side::Black, resources[Resources::blackRook]));
}
