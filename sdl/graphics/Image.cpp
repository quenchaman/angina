/*
 * Image.cpp
 *
 *  Created on: Oct 30, 2021
 *      Author: ubuntu
 */


#include "Image.h"

Image::Image(Texture& _texture, SDL_Rect _boundingBox)
	: position(*(new Point(0, 0))), texture(_texture), boundingBox(_boundingBox) {
}

void Image::draw(Renderer& renderer) {
	this->texture.draw(renderer, &this->boundingBox);
}

void Image::moveUp(int32_t y) {
	int32_t currentY = this->boundingBox.y;
	int32_t newY = currentY;

	if (-newY + Globals::config.screenHeight + y <= this->boundingBox.h) {
		newY -= y;
	}

	this->boundingBox.y = newY;

	std::cout << "New position: x -> " << this->boundingBox.x << ", y -> " << this->boundingBox.y << std::endl;
}

void Image::moveDown(int32_t y) {
	int32_t currentY = this->boundingBox.y;
	int32_t newY = currentY;

	if (newY + y <= 0) {
		newY += y;
	}

	this->boundingBox.y = newY;

	std::cout << "New position: x -> " << this->boundingBox.x << ", y -> " << this->boundingBox.y << std::endl;
}

void Image::moveLeft(int32_t x) {
	int32_t currentX = this->boundingBox.x;
	int32_t newX = currentX;

	if (-newX + Globals::config.screenWidth + x <= this->boundingBox.w) {
		newX -= x;
	}

	this->boundingBox.x = newX;

	std::cout << "New position: x -> " << this->boundingBox.x << ", y -> " << this->boundingBox.y << std::endl;
}

void Image::moveRight(int32_t x) {
	int32_t currentX = this->boundingBox.x;
	int32_t newX = currentX;

	if (newX + x <= 0) {
		newX += x;
	}

	this->boundingBox.x = newX;

	std::cout << "New position: x -> " << this->boundingBox.x << ", y -> " << this->boundingBox.y << std::endl;
}

void Image::setX(int32_t x) {
	this->boundingBox.x = x;
}

void Image::setY(int32_t y) {
	this->boundingBox.y = y;
}
