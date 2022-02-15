#include "GraphicsFactory.h"

#include "sdl/resources/ResourceLoader.h"
#include "sdl/graphics/Surface.h"
#include "sdl/graphics/Renderer.h"

GraphicsFactory::GraphicsFactory(const Renderer& r): renderer(r) {
}

Object* GraphicsFactory::createObject(const std::string& resourcePath, Point position) const {
	Surface* surface = ResourceLoader::load(resourcePath);

	return renderer.fromSurface(*surface);
}
