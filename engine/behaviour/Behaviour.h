#ifndef ENGINE_BEHAVIOUR_BEHAVIOUR_H_
#define ENGINE_BEHAVIOUR_BEHAVIOUR_H_

#include "engine/Engine.h"

/**
 * Wraps a target and enforces the implementation of life-cycle methods on a target.
 */
template <typename T>
class Behaviour {
public:
	Behaviour(T& targetObj): target(targetObj) {}
	virtual ~Behaviour() = default;

	/* used for setup logic and will be run once, in the start of the game. */
	virtual void start() = 0;

	/* called on every frame */
	virtual void update() = 0;

	Behaviour& setEngine(Engine& engine) {
		this->engine = engine;

		return *this;
	}
private:
	Engine* engine = nullptr;
	T& target;
};

#endif /* ENGINE_BEHAVIOUR_BEHAVIOUR_H_ */
