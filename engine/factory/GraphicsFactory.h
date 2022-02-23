#ifndef SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_
#define SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_

#include <string>

#include "renderer/primitives/Point.h"
#include "renderer/shapes/Rect.h"
#include "renderer/primitives/Color.h"


struct Renderer;
struct Object;
struct RectTextButton;
struct Font;
struct Text;

class GraphicsFactory {
public:
	GraphicsFactory(Renderer& renderer);

	Object* createObject(const std::string& resourcePath, Point p, Dimensions dim);

	Text* createText(std::string text, Font& font, Point p, Dimensions dim, Color color = Color::NONE);

	RectTextButton* createButton(Point p, Dimensions dim, Color backgroundColor, Color textColor, std::string text, Font& font, void (*clb)());
private:
	Renderer& renderer;
};

#endif /* SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_ */
