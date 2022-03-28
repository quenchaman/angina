#include "GraphicsFactory.h"

#include "platform/sdl/resource-loader/ResourceLoader.h"
#include "platform/sdl/primitives/Surface.h"
#include "renderer/Renderer.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "platform/sdl/primitives/Font.h"
#include "renderer/primitives/Text.h"
#include "renderer/shapes/Rect.h"
#include "engine/components/buttons/RectTextButton.h"

GraphicsFactory::GraphicsFactory(Renderer &r) :
        renderer(r) {
}

Object* GraphicsFactory::createObject(const std::string &resourcePath, Point p,
        Dimensions dim) {
    Surface *surface = ResourceLoader::load(resourcePath);

    Object *obj = renderer.fromSurface(*surface, p, dim);

    return obj;
}

Text* GraphicsFactory::createText(std::string textVal, Font &font, Point p,
        Dimensions dim, Color color) {
    Surface *surface = ResourceLoader::loadText(font.getFont(), textVal, color);
    Texture *texture = renderer.from(*surface);
    Text *text = new Text(*texture, dim, p);

    return text;
}

RectTextButton* GraphicsFactory::createButton(Point p, Dimensions dim,
        Color backgroundColor, Color textColor, std::string text, Font &font,
        std::function<void(void)> clb) {
    Text *btnText = GraphicsFactory::createText(text, font, p, dim, textColor);

    // TODO: Add a padding to the text or ,even better, center it.

    return new RectTextButton(p, dim, backgroundColor, *btnText, clb);
}

Rect* GraphicsFactory::createRect(Point p, Dimensions dim, Color c) {
	return new Rect(p, dim, c);
}

GraphicsFactory::~GraphicsFactory() {
    std::cout << "GraphicsFactory destroyed" << std::endl;
}
