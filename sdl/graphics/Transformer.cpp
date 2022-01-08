/*
 * Transformer.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#include "Transformer.h"

#include <cstdint>

#include "SDL.h"

#include "sdl/graphics/Renderer.h"
#include "sdl/graphics/Surface.h"
#include "sdl/graphics/Texture.h"
#include "sdl/engine/object/Object.h"
#include "sdl/primitives/Color.h"
#include "sdl/primitives/Point.h"
#include "sdl/primitives/Rect.h"
#include "sdl/components/Button.h"

#include "exceptions/GraphicsInitException.h"

namespace Transformer {
	Texture* transformSurfaceToTexture(Renderer& renderer, Surface& surface) {
		SDL_Texture* texture = SDL_CreateTextureFromSurface(
				renderer.getRenderer(),
				surface.getSurface()
		);

		if (texture == nullptr) {
			throw GraphicsInitException(SDL_GetError());
		}

		int32_t width = surface.getSurface()->w;
		int32_t height = surface.getSurface()->h;

		return new Texture(texture, width, height);
	}

	std::vector<Texture*> transformSurfacesToTextures(Renderer* renderer, const std::vector<Surface*>& surfaces) {
		std::vector<Texture*> textures;

		for (Surface* surface : surfaces) {
			Texture* t = Transformer::transformSurfaceToTexture(*renderer, *surface);
			textures.push_back(t);
		}

		return textures;
	}

	Object* transformTextureToObject(Renderer& renderer, Texture& texture) {
		Rect* rect = new Rect(Point::UNDEFINED, {texture.w, texture.h}, Color::NONE);
		Object* object = new Object(texture, *rect, renderer);

		return object;
	}

	Button* transformTextureToButton(Renderer& renderer, Texture& texture) {
		Rect* rect = new Rect(Point::UNDEFINED, {texture.w, texture.h}, Color::NONE);
		Button* btn = new Button(texture, *rect, renderer);

		return btn;
	}
}
