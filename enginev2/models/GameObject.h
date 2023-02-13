#ifndef ENGINEV2_MODELS_GAMEOBJECT_H_
#define ENGINEV2_MODELS_GAMEOBJECT_H_

#include "enginev2/graphics/models/Point.h"

class GameObject {
public:
    GameObject(const Point&);
    
    virtual ~GameObject() = default;

    Point pos;
};

#endif /* ENGINEV2_MODELS_GAMEOBJECT_H_ */
