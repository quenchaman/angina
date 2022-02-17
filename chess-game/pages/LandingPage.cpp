#include "LandingPage.h"

#include "chess-game/enums/ChessAssets.h"
#include "resources/Resources.h"
#include "sdl/engine/object/Object.h"
#include "sdl/primitives/Point.h"
#include "sdl/components/Button.h"
#include "config/Config.h"
#include "sdl/engine/factory/GraphicsFactory.h"

LandingPage::LandingPage(Renderer& renderer): Page(renderer) {
	onPageLoad();
}

void LandingPage::onPageLoad() {
//	Button& btn = graphicsFactory.
//	addButton(ChessAssets::NEW_GAME_BUTTON, Resources::newGameButton, Config::NEW_GAME_BTN_POS);
	Object& background = graphicsFactory.createObject(Resources::startScreen2, Point::ZERO);

	addObject(ChessAssets::START_SCREEN_BACKGROUND_IMAGE, background, 0);
}
