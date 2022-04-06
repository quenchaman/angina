#ifndef SDL_ENGINE_PAGE_PAGE_H_
#define SDL_ENGINE_PAGE_PAGE_H_

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <set>
#include <functional>

#include "renderer/primitives/Point.h"
#include "engine/managers/ButtonManager.h"
#include "platform/ids/IdGenerator.h"

struct Button;
struct Drawable;
struct Object;
struct BaseButton;
struct Rect;

/**
 * Class that represents a full screen page.
 * It is a container for objects, rectangles, etc. and provides a way to add and get these primitives for drawing.
 *
 * Does not handle resource destruction.
 */
class Screen {
public:
	Screen();
	~Screen();

	void put(Drawable& drawable);

	const std::vector<Drawable*>& getDrawables();
private:
	std::vector<Drawable*> drawables;
};

#endif /* SDL_ENGINE_PAGE_PAGE_H_ */
