#include "TowerDefence.h"

#include <iostream>
#include <vector>

#include "resources/Resources.h"

// TODO: Move Point and Dimensions to the 'core' package.
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Line.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Grid.h"
#include "engine/components/buttons/RectTextButton.h"
#include "renderer/shapes/Rect.h"

#include "engine/sprites/Sprite.h"

#include "examples/towerdefence/HeroController.h"
#include "examples/towerdefence/TDConfig.h"

TowerDefence::TowerDefence(): Engine("Tower Defence", TDConfig::GAME_DIM), sprite(nullptr) {}

void TowerDefence::init() {
	buildStartPage();
}

void TowerDefence::update() {
}

void TowerDefence::handleLeftMouseClick([[maybe_unused]] Point p) {

}

void TowerDefence::handleBtnClick([[maybe_unused]]int32_t idx) {

}

void TowerDefence::buildStartPage() {
	initialiseScreen();

	Object& startBG = getFactory().createObject(Resources::TD::background, Point::ZERO, TDConfig::GAME_DIM);
	addComponent(startBG);
	RectTextButton& mapBuilderButton = getFactory().createButton(
			Point {730, 580},
			Dimensions{ 50, 50 },
			Color::BLUE,
			"MB",
			std::bind(&TowerDefence::onMapBuilderBtn, this));
	addComponent(mapBuilderButton);
}

void TowerDefence::onMapBuilderBtn() {
	initMapBuilder();
}
