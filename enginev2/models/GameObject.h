#ifndef ENGINEV2_MODELS_GAMEOBJECT_H_
#define ENGINEV2_MODELS_GAMEOBJECT_H_

#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"

struct SDL_Texture;
struct Texture;
struct TextureRendererComponent;

class GameObject {
public:
    friend class TextureRendererComponent;

    GameObject(const Point&, SDL_Texture&);
    GameObject(const Point&, SDL_Texture&, const Rectangle& clip);
    virtual ~GameObject();
private:
    Point pos;
    Texture* tx;
};

#endif /* ENGINEV2_MODELS_GAMEOBJECT_H_ */
