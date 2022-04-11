#ifndef SDL_GRAPHICS_RENDERER_H_
#define SDL_GRAPHICS_RENDERER_H_

#include <vector>
#include <cstdint>

#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Point.h"

struct SDL_Renderer;
struct Texture;
struct Rect;
struct Window;
struct Object;
struct MovingObject;
struct Surface;
struct Button;
struct Line;

class Renderer {
public:
	Renderer(Window&);
	~Renderer();

	void clear();
	void render(const Texture&) const;
	void render(Rect&) const;
	void render(Object&) const;
	void render(Line&) const;
	void update();

	Texture& from(Surface&) const;
	Object& from(Texture&, Point, Dimensions) const;
	MovingObject& from(Texture&, Point, Dimensions, int32_t velocity, Point dest) const;
	Object& fromSurface(Surface&, Point, Dimensions) const;
	Button& from(Texture&);
private:
	void init(Window&);
	void deinit();

	SDL_Renderer *renderer;
};

#endif /* SDL_GRAPHICS_RENDERER_H_ */
