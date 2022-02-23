#include "Texture.h"

#include "SDL_image.h"

Texture::Texture(SDL_Texture* _texture, Dimensions dim): texture(_texture), dimensions(dim) {}

SDL_Texture* Texture::getTexture() const {
	return texture;
}

Dimensions Texture::getDimensions() const {
	return dimensions;
}

Texture::~Texture() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}

	std::cout << "Texture destroyed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Texture& t) {
	return os << "Texture with width: " << t.dimensions.w << " and height: " << t.dimensions.h;
}
