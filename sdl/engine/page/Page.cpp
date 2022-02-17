#include "Page.h"

#include "renderer/Renderer.h"
#include "sdl/resources/ResourceLoader.h"
#include "resources/Resources.h"
#include "renderer/primitives/Color.h"
#include "platform/sdl/primitives/Texture.h"
#include "platform/sdl/shapes/Rect.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Button.h"
#include "renderer/primitives/Point.h"

Page::Page(Renderer& renderer): _renderer(renderer) {
	font = ResourceLoader::loadFont(Resources::montserratFont, 28);
}

Page::~Page() {

}

// TODO: We need a better way to generate Ids.
void Page::addRectangle([[maybe_unused]]const int32_t id, [[maybe_unused]]const Rect& rectangle, [[maybe_unused]]int32_t zIndex) {

}

void Page::addObject([[maybe_unused]]const int32_t id, [[maybe_unused]]const Object& object, [[maybe_unused]]int32_t zIndex) {

}
void Page::addButton(const int32_t id, Button& btn, [[maybe_unused]]int32_t zIndex) {
	buttonManager.registerButton(id, btn);
}
