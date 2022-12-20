#ifndef ENGINEV2_COMPONENTS_GAMEOBJECTCOMPONENT_H_
#define ENGINEV2_COMPONENTS_GAMEOBJECTCOMPONENT_H_

#include <string>

struct Point;

#include "enginev2/components/PrimitivesComponent.h"
#include "enginev2/models/GameObject.h"

class GameObjectComponent : private PrimitivesComponent<GameObject> {
public:
    friend class GameEngine;

    //GameObjectComponent();
    //void init(TextureLoaderComponent&);

    void loadGameObject(const std::string& textureResourcePath, const Point&);
    void loadGameObjectSprite(const std::string& textureResourcePath, const Point&, const Rectangle&);
private:
};

#endif /* ENGINEV2_COMPONENTS_GAMEOBJECTCOMPONENT_H_ */
