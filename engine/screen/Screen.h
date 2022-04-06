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
 *
 * Does not handle resource destruction.
 */
class Screen {
public:
	Screen();
	~Screen();

	int32_t put(BaseButton&);
	int32_t put(Drawable& drawable);

	void remove(int32_t id);

	std::vector<Drawable*> getDrawables();
	//ButtonManager& getButtonManager();

	//void onDestroy(std::function<void(void)> callback);
protected:
	std::unordered_map<int32_t, Drawable*> drawables;
private:
	// ids - for keeping track of insertion order of drawables. This matters for drawing. Later I can add z-index.
	//std::set<int32_t> ids;
	//std::vector<Screen*> children;
	//ButtonManager btnManager;
	//Point origin;
	//IdGenerator &idGen;
	//std::function<void(void)> onDestroyCallback;
};

#endif /* SDL_ENGINE_PAGE_PAGE_H_ */
