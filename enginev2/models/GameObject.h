#ifndef ENGINEV2_MODELS_GAMEOBJECT_H_
#define ENGINEV2_MODELS_GAMEOBJECT_H_

#include <memory>

#include "enginev2/graphics/sdl/primitives/Texture.h"
#include "enginev2/graphics/models/Point.h"
#include "enginev2/graphics/models/Dimensions.h"
#include "enginev2/graphics/animation/Sprite.h"
#include "enginev2/components/ID.h"
#include "platform/ids/ForwardIdGenerator.h"
#include "enginev2/collisions/BoundingBox.h"

class GameObject {
public:
  GameObject() = default;
  GameObject(ID id, Sprite& sprite, float speedFactor, Point pos, Dimensions dim);
   
  void updatePosition(const Point& placementPos);
  void updateDirection(const Point& newDir);
  virtual ~GameObject() = default;

  void setSprite(Sprite s);
  void calculateBB();

  ID id;
  //std::shared_ptr<Texture> tex;
  Sprite sprite;
  float speedFactor; // pixels per second
  Point renderingPos; // Used for rendering and is at the upper left corner of the texture.
  Point placementPos; // The middle of the bottom edge of the object/texture
  Dimensions dim;
  Point dir; // The current direction or last direction the object was travelling towards
  BoundingBox box;
};

struct GameObjectFactory {
  static GameObject create(Sprite& sprite, float speed, Point pos, Dimensions dim) {
    ID id = idgen.next();
    return GameObject(id, sprite, speed, pos, dim);
  }

private:
  static ForwardIdGenerator idgen;
};

#endif /* ENGINEV2_MODELS_GAMEOBJECT_H_ */
