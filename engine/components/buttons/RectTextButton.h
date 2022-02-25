#ifndef ENGINE_COMPONENTS_BUTTONS_RECTTEXTBUTTON_H_
#define ENGINE_COMPONENTS_BUTTONS_RECTTEXTBUTTON_H_

#include <string>

#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Color.h"

#include "engine/components/buttons/BaseButton.h"
#include "renderer/shapes/Rect.h"

struct Text;
struct Renderer;

class RectTextButton : public BaseButton {
public:
	RectTextButton(Point p, Dimensions dim, Color backgroundColor, Text& text, std::function<void(void)> clb);
	~RectTextButton() = default;

	void draw(Renderer& renderer);

private:
	Rect rect;
	Text& text;
};

#endif /* ENGINE_COMPONENTS_BUTTONS_RECTTEXTBUTTON_H_ */
