#include "Texture.h"

#include <iostream>

#include "SDL_image.h"

Texture::Texture(SDL_Texture *_texture) :
		texture(_texture) {
}

Texture::~Texture() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}

	std::cout << "Texture destroyed" << std::endl;
}
