#ifndef ENGINE_MOVEMENT_LINEARFIXEDMOVEMENTMANAGER_H_
#define ENGINE_MOVEMENT_LINEARFIXEDMOVEMENTMANAGER_H_

#include <list>
#include <cstdint>

#include "engine/primitives/MovingObject.h"

class LinearFixedMovementManager {
public:
	LinearFixedMovementManager();

	void addMoveable(MovingObject&);

	void processFrame(int64_t elapsedTime);
private:
	std::list<MovingObject*> moveables;

	void processMoveable(MovingObject&, int64_t elapsedTimeMicro);
};

#endif /* ENGINE_MOVEMENT_LINEARFIXEDMOVEMENTMANAGER_H_ */
