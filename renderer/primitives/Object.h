#ifndef SDL_ENGINE_OBJECT_OBJECT_H_
#define SDL_ENGINE_OBJECT_OBJECT_H_

#include <cstdint>

#include "renderer/primitives/Point.h"
#include "renderer/drawable/Drawable.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Transformation.h"

struct Texture;
struct Renderer;

class Object: public Drawable {
public:
    Object(Texture&, Dimensions, Point);
    ~Object();

    Object(const Object&) = delete;
    Object& operator=(const Object&) = delete;
    Object(Object&&) = delete;
    Object& operator=(Object&&) = delete;

    void draw(Renderer&);
    void move(const int32_t x, const int32_t y);
    void move(const Point&);

    Point getPosition() const;
    Dimensions getDimensions() const;
    Point getCenter() const;

    Texture &texture;
    Transformation transformation;
private:
    Dimensions dim;
    Point point;
    Point center;
};

#endif /* SDL_ENGINE_OBJECT_OBJECT_H_ */
