#ifndef SDL_ENGINE_OBJECT_OBJECT_H_
#define SDL_ENGINE_OBJECT_OBJECT_H_

#include <cstdint>

#include "renderer/primitives/Point.h"
#include "renderer/drawable/Drawable.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Transformation.h"

struct Texture;
struct Renderer;

class Object : public Drawable {
public:
	Object(Texture& t, Dimensions dim, Point point);
	~Object();

	Object(const Object& other) = delete;
	Object& operator=(const Object& other) = delete;
	Object(Object&& other) = delete;
	Object& operator=(Object&& other) = delete;

	void draw(Renderer& renderer);
	void move(const int32_t x, const int32_t y);
	Point getPosition() const;
	Dimensions getDimensions() const;

	Texture& texture;
	Transformation transformation;
private:
	Dimensions dim;
	Point point;
};

#endif /* SDL_ENGINE_OBJECT_OBJECT_H_ */
