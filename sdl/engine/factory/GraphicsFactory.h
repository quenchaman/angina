#ifndef SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_
#define SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_

#include <string>

#include "sdl/primitives/Point.h"

struct Renderer;
struct Object;

class GraphicsFactory {
public:
	GraphicsFactory(const Renderer& renderer);

	Object* createObject(const std::string& resourcePath, Point position) const;
private:
	const Renderer& renderer;
};

#endif /* SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_ */
