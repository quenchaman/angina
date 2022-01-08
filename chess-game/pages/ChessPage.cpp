/*
 * ChessPage.cpp
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#include "ChessPage.h"

#include "chess-game/enums/ChessAssets.h"
#include "resources/Resources.h"
#include "sdl/engine/object/Object.h"
#include "sdl/primitives/Point.h"
#include "sdl/components/Button.h"
#include "chess-game/board/Board.h"

ChessPage::ChessPage(Renderer& renderer) : Page(renderer)  {
	onPageLoad();
}

void ChessPage::onPageLoad() {
	addObject(ChessAssets::START_SCREEN_BACKGROUND_IMAGE, Resources::startScreen2, Point{0, 0});
	addObject(ChessAssets::BOARD, Resources::board, Point{0, 0});
	board = new Board(*objects[ChessAssets::BOARD], Dimensions{80, 80});
}

void ChessPage::draw() {
	objects[ChessAssets::START_SCREEN_BACKGROUND_IMAGE]->draw();
	board->draw();
}

void ChessPage::onPageUnload() {

}
