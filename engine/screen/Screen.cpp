#include "Screen.h"

#include "renderer/Renderer.h"
#include "sdl/resources/ResourceLoader.h"
#include "resources/Resources.h"
#include "renderer/primitives/Color.h"
#include "platform/sdl/primitives/Texture.h"
#include "renderer/shapes/Rect.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Button.h"
#include "renderer/primitives/Point.h"

Screen::Screen() {
	font = ResourceLoader::loadFont(Resources::montserratFont, 28);
}

Screen::~Screen() {

}

// TODO: We need a better way to generate Ids.
void Screen::addRectangle(const int32_t id, Rect& rectangle, [[maybe_unused]]int32_t zIndex) {
	drawables[id] = &rectangle;
}

void Screen::addObject(const int32_t id, Object& object, [[maybe_unused]]int32_t zIndex) {
	drawables[id] = &object;
}

void Screen::addButton([[maybe_unused]]const int32_t id, [[maybe_unused]]Button& btn, [[maybe_unused]]int32_t zIndex) {
	//buttonManager.registerButton(id, btn);
}

std::vector<Drawable*> Screen::getDrawables() const {
	std::vector<Drawable*> d;

	for (auto const& [id, drawable] : drawables) {
		d.push_back(drawable);
	}

	return d;
}
