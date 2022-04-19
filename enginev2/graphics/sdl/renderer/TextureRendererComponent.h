#ifndef ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_
#define ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_

struct SDL_Renderer;
struct Window;
struct Texture;
struct TextureComponent;
struct Rectangle;
struct Pixel;
struct Line;

class TextureRendererComponent {
public:
	friend class TextureComponent;

	~TextureRendererComponent();

	void init(Window&);

	void clear();
	void render(Texture&);
	void render(Texture&, Rectangle& viewPort);
	void render(Rectangle&);
	void render(Pixel&);
	void render(Line&);
	void update();
private:
	SDL_Renderer* sdlRenderer;
};

#endif /* ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_ */
