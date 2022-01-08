/*
 * Transformer.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_COMPONENTS_TRANSFORMER_H_
#define SDL_COMPONENTS_TRANSFORMER_H_

#include <vector>

struct Texture;
struct Renderer;
struct Surface;
struct Object;
struct Button;
struct Point;

namespace Transformer {
	Texture* transformSurfaceToTexture(Renderer& renderer, Surface& surface);
	std::vector<Texture*> transformSurfacesToTextures(Renderer* renderer, const std::vector<Surface*>& surfaces);
	Object* transformTextureToObject(Renderer& renderer, Texture& texture);
	Button* transformTextureToButton(Renderer& renderer, Texture& texture);
}


#endif /* SDL_COMPONENTS_TRANSFORMER_H_ */
