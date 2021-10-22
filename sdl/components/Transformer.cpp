/*
 * Transformer.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#include "Transformer.h"

namespace Transformer {
	Texture* transformSurfaceToTexture(Renderer& renderer, Surface& surface) {
		SDL_Texture* texture = SDL_CreateTextureFromSurface(
				renderer.getRenderer(),
				surface.getSurface()
		);

		if (texture == nullptr) {
			throw GraphicsInitException(SDL_GetError());
		}

		return new Texture(texture);
	}

	std::vector<Texture*> transformSurfacesToTextures(Renderer& renderer, std::vector<Surface*> surfaces) {
		std::vector<Texture*> textures;

		for (Surface* surface : surfaces) {
			Texture* t = Transformer::transformSurfaceToTexture(renderer, *surface);
			textures.push_back(t);
		}

		return textures;
	}
}
