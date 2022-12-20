#ifndef ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_
#define ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_

#include <memory>

#include "SDL_render.h"

struct Window;
struct Texture;
struct TextureComponent;
struct Rectangle;
struct Pixel;
struct Line;
struct GameObject;

class TextureRendererComponent {
public:
	~TextureRendererComponent();

	void init(Window&);

	void clear();
	void render(Texture&);
	void render(GameObject&);
	void render(Texture&, Rectangle& viewPort);
	void render(Rectangle&);
	void render(Pixel&);
	void render(Line&);
	void update();
	std::shared_ptr<SDL_Renderer> get() const;
private:
	std::shared_ptr<SDL_Renderer> renderer;
};

#endif /* ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_ */
