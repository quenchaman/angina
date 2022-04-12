#ifndef EXAMPLES_TOWERDEFENCE_HEROCONTROLLER_H_
#define EXAMPLES_TOWERDEFENCE_HEROCONTROLLER_H_

#include "engine/behaviour/Behaviour.h"
#include "renderer/primitives/Object.h"

class HeroController : public Behaviour<Object> {
public:
	HeroController(Object&);

	void start();

	void update();
};

#endif /* EXAMPLES_TOWERDEFENCE_HEROCONTROLLER_H_ */
