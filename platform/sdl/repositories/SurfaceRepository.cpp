#include "SurfaceRepository.h"

#include "resources/Resources.h"

#include "platform/sdl/primitives/Surface.h"
#include "platform/sdl/resource-loader/ResourceLoader.h"

SurfaceRepository::SurfaceRepository(): textFont(Font(Resources::Engine::montserratFont, 18)), textColor(Color::BLACK) {

}

Surface& SurfaceRepository::get(const std::string& resourcePath) {
    Surface* surface = nullptr;

    if (surfaceCache.exists(resourcePath)) {
        surface = &surfaceCache.get(resourcePath);
    } else {
    	surface = new Surface(
    			Resources::isResource(resourcePath) ?
    			ResourceLoader::loadImage(resourcePath) :
					ResourceLoader::loadText(&textFont.getFont(), resourcePath, textColor)
			);
      surfaceCache.add(resourcePath, *surface);
    }

    return *surface;
}
