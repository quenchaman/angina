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
    for (uint32_t colIdx = 0; colIdx < (uint32_t)8; colIdx++) {
        activePieces.push_back(new Pawn(colIdx, 6, Side::White, new Image(resources[Resources::whitePawn])));
        passivePieces.push_back(new Pawn(colIdx, 1, Side::Black, new Image(resources[Resources::blackPawn])));
    }

    activePieces.push_back(new Rook(0, 7, Side::White, new Image(resources[Resources::whiteRook])));
    activePieces.push_back(new Knight(1, 7, Side::White, new Image(resources[Resources::whiteKnight])));
    activePieces.push_back(new Bishop(2, 7, Side::White, new Image(resources[Resources::whiteBishop])));
    activePieces.push_back(new King(4, 7, Side::White, new Image(resources[Resources::whiteKing])));
    activePieces.push_back(new Queen(3, 7, Side::White, new Image(resources[Resources::whiteQueen])));
    activePieces.push_back(new Bishop(5, 7, Side::White, new Image(resources[Resources::whiteBishop])));
    activePieces.push_back(new Knight(6, 7, Side::White, new Image(resources[Resources::whiteKnight])));
    activePieces.push_back(new Rook(7, 7, Side::White, new Image(resources[Resources::whiteRook])));

    passivePieces.push_back(new Rook(0, 0, Side::Black, new Image(resources[Resources::blackRook])));
    passivePieces.push_back(new Knight(1, 0, Side::Black, new Image(resources[Resources::blackKnight])));
    passivePieces.push_back(new Bishop(2, 0, Side::Black, new Image(resources[Resources::blackBishop])));
    passivePieces.push_back(new King(4, 0, Side::Black, new Image(resources[Resources::blackKing])));
    passivePieces.push_back(new Queen(3, 0, Side::Black, new Image(resources[Resources::blackQueen])));
    passivePieces.push_back(new Bishop(5, 0, Side::Black, new Image(resources[Resources::blackBishop])));
    passivePieces.push_back(new Knight(6, 0, Side::Black, new Image(resources[Resources::blackKnight])));
    passivePieces.push_back(new Rook(7, 0, Side::Black, new Image(resources[Resources::blackRook])));
}
