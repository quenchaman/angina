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
struct Text;
struct Object;
struct MovingObject;
struct Surface;
struct Button;
struct Line;

class Renderer {
public:
	Renderer();
	~Renderer();

	void init(Window&);

	void clear();
	void render(const Texture&) const;
	void render(Rect&) const;
	void render(Object&) const;
	void render(Line&) const;
	void update();
private:
	SDL_Renderer *renderer;
};

#endif /* SDL_GRAPHICS_RENDERER_H_ */
