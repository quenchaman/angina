#include "Texture.h"

#include <iostream>

#include "SDL_image.h"
#include "SDL_render.h"

Texture::Texture(SDL_Texture* tx, Rectangle rect): texture(tx), dim(Dimensions::UNDEFINED), clip(rect) {
    SDL_QueryTexture(texture, NULL, NULL, &dim.w, &dim.h);
}

Texture::Texture(SDL_Texture* _texture): Texture(_texture, Rectangle()) {}

Texture::~Texture() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}

	std::cout << "Texture destroyed" << std::endl;
}
