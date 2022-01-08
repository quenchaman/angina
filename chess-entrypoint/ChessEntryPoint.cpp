//
// Created by ubuntu on 11/28/21.
//

#include "ChessEntryPoint.h"

#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <string>

#include "sdl/primitives/Rect.h"
#include "sdl/engine/object/Object.h"
#include "resources/Resources.h"
#include "sdl/components/Button.h"
#include "sdl/engine/page/Page.h"
#include "sdl/primitives/Point.h"
#include "sdl/primitives/Dimensions.h"
#include "chess-game/pages/LandingPage.h"
#include "chess-game/pages/ChessPage.h"

ChessEntryPoint::~ChessEntryPoint() {

}

void ChessEntryPoint::init() {
	navigateTo(initWelcomePage());
}

void ChessEntryPoint::update() {
}

void ChessEntryPoint::handleLeftMouseClick() {

}

void ChessEntryPoint::handleBtnClick([[maybe_unused]]int32_t idx) {
	if (idx == 1) {
		navigateTo(initChessPage());
	}
}

Page* ChessEntryPoint::initWelcomePage() {
	LandingPage* landing = new LandingPage(*getRenderer());

	return landing;
}

Page* ChessEntryPoint::initChessPage() {
	return new ChessPage(*getRenderer());
}

ChessEntryPoint::ChessEntryPoint() : Engine("Test", { 800, 800 }) {

}
