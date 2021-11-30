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
        populatePiecesMap();
        currentState = State::WHITE;
    } else if (currentState == State::WHITE) {
        currentState = State::HUMAN;
    } else if (currentState == State::BLACK) {
        currentState = State::COMPUTER;
    } else if (currentState == State::HUMAN) {
    	if (!selectedCell.isEmpty) {
    		if (isOwnPiece(getPieceOnCell(selectedCell))) {
    			selectedPiece = getPieceOnCell(selectedCell);
    			currentState = State::AVAILABLE_MOVES;
    		}
    	}
    } else if (currentState == State::AVAILABLE_MOVES) {

    } else if (currentState == State::SELECTED) {
    	// We have to handle changing the piece

    }
}

void Chess::handleLeftMouseClick() {
	int32_t x, y;
	SDL_GetMouseState(&x, &y);
	Cell clickedCell = {x / Piece::PIECE_WIDTH, y / Piece::PIECE_HEIGHT, false};

	if (currentState == State::HUMAN) {
		selectedCell = clickedCell;
	} else if (currentState == State::HUMAN_MOVE) {
		targetCell = clickedCell;
	}

}

Chess::Chess() : Engine("Chess") {
    currentState = State::INITIALIZE_BOARD;
    isWhiteHuman = true;
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

Piece *Chess::getPieceOnCell(Cell cell) {
    for (Piece* piece : activePieces) {
        if (piece->getCol() == cell.col && piece->getRow() == cell.row) {
            return piece;
        }
    }

    for (Piece* piece : passivePieces) {
        if (piece->getCol() == cell.col && piece->getRow() == cell.row) {
            return piece;
        }
    }

    return nullptr;
}

bool Chess::isOwnPiece(Piece *piece) {
    return piece != nullptr && piece->getSide() == currentSide;
}

void Chess::calculateAllMoves() {

}

void Chess::populatePiecesMap() {
	std::vector<Piece*> allPieces = activePieces;
	allPieces.insert(std::end(allPieces), std::begin(passivePieces), std::end(passivePieces));
	for (Piece* p : allPieces) {
		Cell key = {p->getCol(), p->getRow()};
		piecesMap[key] = p;
	}
}
