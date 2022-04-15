#ifndef ENGINEV2_GRAPHICS_SDL_RENDERER_SURFACERENDERER_H_
#define ENGINEV2_GRAPHICS_SDL_RENDERER_SURFACERENDERER_H_

struct SDL_Surface;
struct SDL_Rect;

class SurfaceRenderer {
public:

	void fillRect(SDL_Surface&) const;
	void drawOnSurface(SDL_Surface& src, SDL_Surface& dest) const;
	void drawOnSurface(SDL_Surface& srcImage, SDL_Rect& srcRectangle, SDL_Surface& destImage, SDL_Rect& destRectangle) const;
};

#endif /* ENGINEV2_GRAPHICS_SDL_RENDERER_SURFACERENDERER_H_ */
