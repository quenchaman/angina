/*
 * Image.cpp
 *
 *  Created on: Oct 30, 2021
 *      Author: ubuntu
 */


#include "Image.h"

Image::Image(Texture& _texture, SDL_Rect _boundingBox)
	: texture(_texture), boundingBox(_boundingBox) {
}

void Image::draw(Renderer& renderer) {
	this->texture.draw(renderer, &this->boundingBox);
}

void Image::setX(int32_t x) {
	this->boundingBox.x = x;
}

void Image::setY(int32_t y) {
	this->boundingBox.y = y;
}

Texture *Image::getTexture() {
    return &this->texture;
}

SDL_Rect Image::getBoundingBox() {
    return this->boundingBox;
}

void Image::put(int32_t x, int32_t y) {
    setX(x);
    setY(y);
}

Image::~Image() {
    delete &texture;
}

Image::Image(Image * img): texture(img->texture), boundingBox(img->boundingBox) {
}

Image::Image(Texture &texture): texture(texture) {
    boundingBox = {0, 0, texture.getSize().x, texture.getSize().y};
}
