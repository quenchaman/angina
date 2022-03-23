#ifndef SDL_ENGINE_PAGE_PAGE_H_
#define SDL_ENGINE_PAGE_PAGE_H_

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <set>

#include "renderer/primitives/Point.h"
#include "platform/ids/IdGenerator.h"

struct Button;
struct Drawable;
struct Object;
struct BaseButton;
struct ButtonManager;

/**
 * Class that represents a full screen page.
 * It is a container for objects, rectangles, etc. and provides a way to add and get these primitives for drawing.
 *
 *
 * Handles resource destruction after deinitialization.
 */
class Widget {
public:
	// TODO: Add Buttons manager here and enable adding buttons to it.
	Widget(ButtonManager&);
	Widget(ButtonManager&, Point);
	~Widget();
	void addChild(Widget&);

	int32_t put(BaseButton&);
	int32_t put(Object& drawable);

	void remove(int32_t id);

	std::vector<Drawable*> getDrawables();
	std::vector<Widget*>& getChildren();
private:
	std::unordered_map<int32_t, Drawable*> drawables;
	// ids - for keeping track of insertion order of drawables. This matters for drawing. Later I can add z-index.
	std::set<int32_t> ids;
	std::vector<Widget*> children;
	// Make button manager per widget instance
	ButtonManager& btnManager;
	Point origin;
	IdGenerator idGen;

};

#endif /* SDL_ENGINE_PAGE_PAGE_H_ */
