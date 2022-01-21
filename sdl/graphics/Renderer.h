/*
 * Renderer.h
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_RENDERER_H_
#define SDL_GRAPHICS_RENDERER_H_

struct SDL_Renderer;
struct Texture;
struct Rect;
struct Window;
struct Object;

class Renderer {
public:
	Renderer(Window& window);
	~Renderer();

	SDL_Renderer* getRenderer();
	void clear();
	void render(const Texture& texture) const;
	void render(const Rect& rect) const;
	void render(const Object& object) const;
	void update();
private:
	void init(Window& window);
	void deinit();

	SDL_Renderer* renderer;
};

#endif /* SDL_GRAPHICS_RENDERER_H_ */
