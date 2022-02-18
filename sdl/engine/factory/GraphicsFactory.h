#ifndef SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_
#define SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_

#include <string>

#include "renderer/primitives/Point.h"
#include "renderer/shapes/Rect.h"

struct Renderer;
struct Object;
struct Button;

class GraphicsFactory {
public:
	GraphicsFactory(Renderer& renderer);

	Object* createObject(const std::string& resourcePath, Point p, Dimensions dim) const;

	//Button* createButton(const std::string& resourcePath, Point position) const;
private:
	Renderer& renderer;
};

#endif /* SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_ */
