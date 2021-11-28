/*
 * Transformer.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_COMPONENTS_TRANSFORMER_H_
#define SDL_COMPONENTS_TRANSFORMER_H_

#include <vector>
#include "SDL.h"

#include "sdl/graphics/Renderer.h"
#include "sdl/graphics/Texture.h"
#include "Surface.h"

namespace Transformer {
	Texture* transformSurfaceToTexture(Renderer& renderer, Surface& surface);
	std::vector<Texture*> transformSurfacesToTextures(Renderer* renderer, const std::vector<Surface*>& surfaces);
}


#endif /* SDL_COMPONENTS_TRANSFORMER_H_ */
