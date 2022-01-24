/*
 * LandingPage.cpp
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#include "LandingPage.h"

#include "chess-game/enums/ChessAssets.h"
#include "resources/Resources.h"
#include "sdl/engine/object/Object.h"
#include "sdl/primitives/Point.h"
#include "sdl/components/Button.h"
#include "config/Config.h"

LandingPage::LandingPage(Renderer& renderer): Page(renderer) {
	onPageLoad();
}

void LandingPage::onPageLoad() {
	addButton(ChessAssets::NEW_GAME_BUTTON, Resources::newGameButton, Config::NEW_GAME_BTN_POS);

	addObject(ChessAssets::START_SCREEN_BACKGROUND_IMAGE, Resources::startScreen2, Point{0, 0});
}

void LandingPage::draw() {
	objects[ChessAssets::START_SCREEN_BACKGROUND_IMAGE]->draw();
	buttonManager.getButton(ChessAssets::NEW_GAME_BUTTON).draw();
}

void LandingPage::onPageUnload() {

}
