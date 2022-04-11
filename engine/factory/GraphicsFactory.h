#ifndef SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_
#define SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_

#include <string>
#include <functional>

#include "renderer/primitives/Point.h"
#include "renderer/shapes/Rect.h"
#include "renderer/primitives/Color.h"

struct Renderer;
struct Object;
struct MovingObject;
struct RectTextButton;
struct Font;
struct Text;
struct Rect;
struct TextureRepository;

/*
 * Creates game objects, text, buttons, rectangles.
 */
class GraphicsFactory {
public:
	GraphicsFactory(Renderer&, TextureRepository&);

	Object& createObject(const std::string &resourcePath, Point, Dimensions);

	//Text& createText(const std::string text, Font&, Point, Dimensions, Color color = Color::BLACK);

	Rect& createRect(Point, Dimensions, Color);

//	RectTextButton& createButton(Point, Dimensions, Color backgroundColor,
//			Color textColor, std::string text, Font&, std::function<void(void)>);
private:
	Renderer &renderer;
	TextureRepository& textureRepo;
};

#endif /* SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_ */
