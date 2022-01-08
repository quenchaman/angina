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

LandingPage::LandingPage(Renderer& renderer): Page(renderer) {
	onPageLoad();
}

void LandingPage::onPageLoad() {
	addButton(0, Resources::gas, Point{0, 0});
	addButton(1, Resources::brake, Point{150, 0});

	addObject(ChessAssets::START_SCREEN_BACKGROUND_IMAGE, Resources::startScreen2, Point{0, 0});
}

void LandingPage::draw() {
	objects[ChessAssets::START_SCREEN_BACKGROUND_IMAGE]->draw();
}

void LandingPage::onPageUnload() {

}
