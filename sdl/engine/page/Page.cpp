#include "Page.h"

#include "sdl/graphics/Renderer.h"
#include "sdl/resources/ResourceLoader.h"
#include "resources/Resources.h"
#include "sdl/primitives/Color.h"
#include "sdl/graphics/Texture.h"
#include "sdl/primitives/Rect.h"
#include "sdl/engine/object/Object.h"
#include "sdl/components/Button.h"
#include "sdl/primitives/Point.h"
#include "sdl/engine/drawables/Drawable.h"
#include "sdl/engine/factory/GraphicsFactory.h"

Page::Page(Renderer& renderer): _renderer(renderer), graphicsFactory(new GraphicsFactory(renderer)) {
	font = ResourceLoader::loadFont(Resources::montserratFont, 28);
}

Page::~Page() {

}

void Page::addRectangle(const int32_t id, const Rect& rectangle, int32_t zIndex) {
	Drawable<Rect>* d = new Drawable<Rect>(rectangle, zIndex);

	drawables[id] = d;
}

void Page::addObject(const int32_t id, const Object& object, int32_t zIndex) {
	Drawable<Object>* d = new Drawable(object, zIndex);

	drawables[id] = d;
}
void Page::addButton(const int32_t id, const Button& btn, int32_t zIndex) {
	buttonManager.registerButton(id, btn);
	Drawable<Button>* d = new Drawable(btn, zIndex);

	drawables[id] = d;
}
