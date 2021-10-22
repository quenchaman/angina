/*
 * Texture.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#include "Texture.h"

Texture::Texture(): texture(nullptr) {}

SDL_Texture* Texture::getTexture() {
	return this->texture;
}

Texture::Texture(SDL_Texture* _texture) {
	this->texture = _texture;
}

void Texture::draw(Renderer& renderer) {
	std::cout << "Hello madafakaz" << std::endl;
}

Texture::~Texture() {}
