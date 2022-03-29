#include "Font.h"

#include <iostream>

#include "platform/sdl/resource-loader/ResourceLoader.h"

Font::Font(const std::string &path, int32_t pointSize) :
		font(ResourceLoader::loadFont(path, pointSize)), size(pointSize) {
}

TTF_Font* Font::getFont() const {
	return font;
}

int32_t Font::getSize() const {
	return size;
}

Font::~Font() {
	TTF_CloseFont(font);
	font = nullptr;
	std::cout << "Font destroyed" << std::endl;
}
