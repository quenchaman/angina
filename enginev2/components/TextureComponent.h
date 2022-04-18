#ifndef ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_
#define ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_

#include <vector>
#include <string>

#include "enginev2/graphics/sdl/primitives/Texture.h"

struct GameEngine;
struct TextureRendererComponent;

class TextureComponent {
public:
	friend class GameEngine;

	TextureComponent();

	void loadSurface(const std::string& resourcePath, TextureRendererComponent&);
private:
	std::vector<Texture> textures;
};

#endif /* ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_ */
