#ifndef ENGINE_BEHAVIOUR_OBJECTBEHAVIOUR_H_
#define ENGINE_BEHAVIOUR_OBJECTBEHAVIOUR_H_

#include "engine/behaviour/Behaviour.h"
#include "renderer/primitives/Object.h"

class ObjectBehaviour : Behaviour<Object> {
    ObjectBehaviour(Object& targetObj): Behaviour(targetObj) {}
}


#endif /* ENGINE_BEHAVIOUR_OBJECTBEHAVIOUR_H_ */
