#ifndef ENGINEV2_MODELS_GAMEOBJECT_H_
#define ENGINEV2_MODELS_GAMEOBJECT_H_

#include <memory>

#include "enginev2/graphics/sdl/primitives/Texture.h"
#include "enginev2/graphics/models/Point.h"
#include "enginev2/graphics/models/Dimensions.h"
#include "enginev2/graphics/animation/Sprite.h"
#include "enginev2/components/ID.h"
#include "platform/ids/ForwardIdGenerator.h"

class GameObject {
public:
  GameObject() = default;
  GameObject(ID id, std::shared_ptr<Sprite> spritePtr, float speedFactor, Point pos,
    Dimensions dim);
    
  virtual ~GameObject() = default;

  ID id;
  //std::shared_ptr<Texture> tex;
  std::shared_ptr<Sprite> spritePtr;
  float speedFactor;
  Point pos;
  Dimensions dim;
};

struct GameObjectFactory {
  static GameObject create(std::shared_ptr<Sprite> spritePtr, float speed, Point pos, Dimensions dim) {
    ID id = idgen.next();
    return GameObject(id, spritePtr, speed, pos, dim);
  }

private:
  static ForwardIdGenerator idgen;
};

#endif /* ENGINEV2_MODELS_GAMEOBJECT_H_ */
