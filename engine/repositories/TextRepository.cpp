#include "TextRepository.h"

#include "renderer/primitives/Text.h"

#include "engine/factory/GraphicsFactory.h"

#include "platform/sdl/primitives/Font.h"

TextRepository::TextRepository(GraphicsFactory& factory, Font& textFont): gFactory(factory), font(textFont) {}

TextRepository::~TextRepository() {
    for (auto const& [txt, texture] : data) {
        delete texture;
    }
}

Text* TextRepository::get(std::string text) {
    bool exists = data.find(text) != data.end();

    if (!exists) {
        Text* textTexture = gFactory.createText(text, font, Point::UNDEFINED, Dimensions::UNDEFINED);

        data[text] = textTexture;
    }

    return data[text];
}
