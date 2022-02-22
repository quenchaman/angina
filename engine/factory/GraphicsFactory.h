#ifndef SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_
#define SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_

#include <string>

#include "renderer/primitives/Point.h"
#include "renderer/shapes/Rect.h"
#include "renderer/primitives/Color.h"


struct Renderer;
struct Object;
struct Button;
struct Font;
struct Text;

class GraphicsFactory {
public:
	GraphicsFactory(Renderer& renderer);

	Object* createObject(const std::string& resourcePath, Point p, Dimensions dim) const;

	Text* createText(std::string text, Font& font, Point p, Dimensions dim, Color color = Color::NONE);

	//Button* createButton(const std::string& resourcePath, Point position) const;
private:
	Renderer& renderer;
};

#endif /* SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_ */
