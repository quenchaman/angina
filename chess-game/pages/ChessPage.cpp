/*
 * ChessPage.cpp
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#include "ChessPage.h"

#include "sdl/engine/object/Object.h"
#include "sdl/primitives/Point.h"
#include "sdl/components/Button.h"
#include "chess-game/board/Board.h"
#include "resources/Resources.h"
#include "chess-game/pieces/Piece.h"

ChessPage::ChessPage(Renderer& renderer) : Page(renderer)  {
	onPageLoad();
}

void ChessPage::onPageLoad() {
	addObject(ChessAssets::START_SCREEN_BACKGROUND_IMAGE, Resources::startScreen2, Point{0, 0});
	addObject(ChessAssets::BOARD, Resources::board, Point{0, 0});
	board = new Board(*objects[ChessAssets::BOARD], Dimensions{80, 80});

	createPiece(ChessAssets::WHITE_ROOK_ON_BLACK, Resources::whiteRook, Cell{7, 0}, Rank::ROOK, Side::White);
	createPiece(ChessAssets::WHITE_KNIGHT_ON_WHITE, Resources::whiteKnight, Cell{7, 1}, Rank::KNIGHT, Side::White);
	createPiece(ChessAssets::WHITE_BISHOP_ON_BLACK, Resources::whiteBishop, Cell{7, 2}, Rank::BISHOP, Side::White);
	createPiece(ChessAssets::WHITE_QUEEN, Resources::whiteQueen, Cell{7, 3}, Rank::QUEEN, Side::White);
	createPiece(ChessAssets::WHITE_KING, Resources::whiteKing, Cell{7, 4}, Rank::KING, Side::White);
	createPiece(ChessAssets::WHITE_BISHOP_ON_WHITE, Resources::whiteBishop, Cell{7, 5}, Rank::BISHOP, Side::White);
	createPiece(ChessAssets::WHITE_KNIGHT_ON_BLACK, Resources::whiteKnight, Cell{7, 6}, Rank::KNIGHT, Side::White);
	createPiece(ChessAssets::WHITE_ROOK_ON_WHITE, Resources::whiteRook, Cell{7, 7}, Rank::ROOK, Side::White);

	createPiece(ChessAssets::WHITE_PAWN_1, Resources::whitePawn, Cell{6, 0}, Rank::PAWN, Side::White);
	createPiece(ChessAssets::WHITE_PAWN_2, Resources::whitePawn, Cell{6, 1}, Rank::PAWN, Side::White);
	createPiece(ChessAssets::WHITE_PAWN_3, Resources::whitePawn, Cell{6, 2}, Rank::PAWN, Side::White);
	createPiece(ChessAssets::WHITE_PAWN_4, Resources::whitePawn, Cell{6, 3}, Rank::PAWN, Side::White);
	createPiece(ChessAssets::WHITE_PAWN_5, Resources::whitePawn, Cell{6, 4}, Rank::PAWN, Side::White);
	createPiece(ChessAssets::WHITE_PAWN_6, Resources::whitePawn, Cell{6, 5}, Rank::PAWN, Side::White);
	createPiece(ChessAssets::WHITE_PAWN_7, Resources::whitePawn, Cell{6, 6}, Rank::PAWN, Side::White);
	createPiece(ChessAssets::WHITE_PAWN_8, Resources::whitePawn, Cell{6, 7}, Rank::PAWN, Side::White);

	createPiece(ChessAssets::BLACK_ROOK_ON_WHITE, Resources::blackRook, Cell{0, 0}, Rank::ROOK, Side::White);
	createPiece(ChessAssets::BLACK_KNIGHT_ON_BLACK, Resources::blackKnight, Cell{0, 1}, Rank::KNIGHT, Side::White);
	createPiece(ChessAssets::BLACK_BISHOP_ON_WHITE, Resources::blackBishop, Cell{0, 2}, Rank::BISHOP, Side::White);
	createPiece(ChessAssets::BLACK_QUEEN, Resources::blackQueen, Cell{0, 3}, Rank::QUEEN, Side::White);
	createPiece(ChessAssets::BLACK_KING, Resources::blackKing, Cell{0, 4}, Rank::KING, Side::White);
	createPiece(ChessAssets::BLACK_BISHOP_ON_BLACK, Resources::blackBishop, Cell{0, 5}, Rank::BISHOP, Side::White);
	createPiece(ChessAssets::BLACK_KNIGHT_ON_WHITE, Resources::blackKnight, Cell{0, 6}, Rank::KNIGHT, Side::White);
	createPiece(ChessAssets::BLACK_ROOK_ON_BLACK, Resources::blackRook, Cell{0, 7}, Rank::ROOK, Side::White);

	createPiece(ChessAssets::BLACK_PAWN_1, Resources::blackPawn, Cell{1, 0}, Rank::PAWN, Side::Black);
	createPiece(ChessAssets::BLACK_PAWN_2, Resources::blackPawn, Cell{1, 1}, Rank::PAWN, Side::Black);
	createPiece(ChessAssets::BLACK_PAWN_3, Resources::blackPawn, Cell{1, 2}, Rank::PAWN, Side::Black);
	createPiece(ChessAssets::BLACK_PAWN_4, Resources::blackPawn, Cell{1, 3}, Rank::PAWN, Side::Black);
	createPiece(ChessAssets::BLACK_PAWN_5, Resources::blackPawn, Cell{1, 4}, Rank::PAWN, Side::Black);
	createPiece(ChessAssets::BLACK_PAWN_6, Resources::blackPawn, Cell{1, 5}, Rank::PAWN, Side::Black);
	createPiece(ChessAssets::BLACK_PAWN_7, Resources::blackPawn, Cell{1, 6}, Rank::PAWN, Side::Black);
	createPiece(ChessAssets::BLACK_PAWN_8, Resources::blackPawn, Cell{1, 7}, Rank::PAWN, Side::Black);
}

void ChessPage::draw() {
	objects[ChessAssets::START_SCREEN_BACKGROUND_IMAGE]->draw();
	board->draw();
}

void ChessPage::createPiece(ChessAssets asset, std::string resource, Cell cell, Rank rank, Side side) {
	addObject(asset, resource, Point::UNDEFINED);
	Piece* piece = new Piece(*objects[asset], cell, side, rank);
	board->putPiece(*piece);
}

void ChessPage::onPageUnload() {

}
