#include "GraphicsFactory.h"

#include "platform/sdl/resource-loader/ResourceLoader.h"
#include "platform/sdl/primitives/Surface.h"
#include "renderer/Renderer.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "platform/sdl/primitives/Font.h"
#include "renderer/primitives/Text.h"

GraphicsFactory::GraphicsFactory(Renderer& r): renderer(r) {
}

Object* GraphicsFactory::createObject(const std::string& resourcePath, Point p, Dimensions dim) const {
	Surface* surface = ResourceLoader::load(resourcePath);

	Object* obj = renderer.fromSurface(*surface, p, dim);

	return obj;
}

Text* GraphicsFactory::createText(std::string textVal, Font& font, Point p, Dimensions dim, Color color) {
	Surface* surface = ResourceLoader::loadText(font.getFont(), textVal, color);
	Texture* texture = renderer.from(*surface);
	Text* text = new Text(*texture, dim, p);

	return text;
}

//Button* GraphicsFactory::createButton(const std::string& resourcePath, Point position) const {
//	Surface* surface = ResourceLoader::load(resourcePath);
//	Texture& texture = renderer.from(*surface);
//
//	return new Button(texture, )
//}
