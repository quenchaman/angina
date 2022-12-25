#ifndef ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_
#define ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_

class Window;
class Texture;
class TextureComponent;
class Rectangle;
class Pixel;
class Line;
class GameObject;
class Sprite;

struct SDL_Renderer;

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
	void render(Sprite&);
	void update();
	SDL_Renderer* get() const;
private:
	SDL_Renderer* renderer;
};

#endif /* ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_ */
