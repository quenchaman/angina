#ifndef ENGINE_COMPONENTS_BUTTONS_RECTTEXTBUTTON_H_
#define ENGINE_COMPONENTS_BUTTONS_RECTTEXTBUTTON_H_

#include <string>

#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Color.h"

#include "engine/components/buttons/BaseButton.h"

struct Rect;
struct Text;
struct Renderer;

class RectTextButton : public BaseButton {
public:
	RectTextButton(Point p, Dimensions dim, Color backgroundColor, Text& text, void (*clb)());
	~RectTextButton();

	void draw(Renderer& renderer);

private:
	Rect* rect;
	Text* text;
};

#endif /* ENGINE_COMPONENTS_BUTTONS_RECTTEXTBUTTON_H_ */
