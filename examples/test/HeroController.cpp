#include "HeroController.h"

HeroController::HeroController(Object& hero): Behaviour(hero) {

}

void HeroController::start() {
	std::cout << "This should be run only once" << std::endl;
}

void HeroController::update() {
	std::cout << "This should be run on every frame" << std::endl;
}
