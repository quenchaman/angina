#ifndef SDL_GRAPHICS_RENDERER_H_
#define SDL_GRAPHICS_RENDERER_H_

#include <vector>

struct SDL_Renderer;
struct Texture;
struct Rect;
struct Window;
struct Object;
struct Surface;
struct Button;

class Renderer {
public:
	Renderer(Window& window);
	~Renderer();

	SDL_Renderer* getRenderer();
	void clear();
	void render(const Texture& texture) const;
	void render(const Rect& rect) const;
	void render(Object& object) const;
	void update();

	Texture* from(Surface& surface) const;
	std::vector<Texture*> from(const std::vector<Surface*>& surfaces) const;
	Object* from(Texture& texture) const;
	Object* fromSurface(Surface& surface) const;
	Button* from(Texture& texture);
private:
	void init(Window& window);
	void deinit();

	SDL_Renderer* renderer;
};

#endif /* SDL_GRAPHICS_RENDERER_H_ */
