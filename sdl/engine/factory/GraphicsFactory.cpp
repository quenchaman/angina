#include "GraphicsFactory.h"

#include "sdl/resources/ResourceLoader.h"
#include "platform/sdl/primitives/Surface.h"
#include "renderer/Renderer.h"
#include "renderer/primitives/Object.h"

GraphicsFactory::GraphicsFactory(Renderer& r): renderer(r) {
}

Object* GraphicsFactory::createObject(const std::string& resourcePath, Point p, Dimensions dim) const {
	Surface* surface = ResourceLoader::load(resourcePath);

	Object* obj = renderer.fromSurface(*surface, p, dim);

	return obj;
}

//Button* GraphicsFactory::createButton(const std::string& resourcePath, Point position) const {
//	Surface* surface = ResourceLoader::load(resourcePath);
//	Texture& texture = renderer.from(*surface);
//
//	return new Button(texture, )
//}
