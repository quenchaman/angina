#ifndef SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_
#define SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_

#include <string>

#include "sdl/primitives/Point.h"

struct Renderer;
struct Object;
struct Button;

class GraphicsFactory {
public:
	GraphicsFactory(const Renderer& renderer);

	Object* createObject(const std::string& resourcePath, Point position) const;

	//Button* createButton(const std::string& resourcePath, Point position) const;
private:
	Renderer& renderer;
};

#endif /* SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_ */
