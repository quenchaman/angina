#include "SurfaceRenderer.h"

#include <SDL.h>

void SurfaceRenderer::fillRect(SDL_Surface& surface) const {
	SDL_FillRect(&surface, NULL, SDL_MapRGB( surface.format, 0xFF, 0xFF, 0xFF ));
}

void SurfaceRenderer::drawOnSurface(SDL_Surface& src, SDL_Surface& dest) const {
	SDL_BlitSurface(&src, nullptr, &dest, nullptr);
}

void SurfaceRenderer::drawOnSurface(SDL_Surface& srcImage, SDL_Rect& srcRectangle, SDL_Surface& destImage, SDL_Rect& destRectangle) const {
	SDL_BlitSurface(&srcImage, &srcRectangle, &destImage, &destRectangle);
}
