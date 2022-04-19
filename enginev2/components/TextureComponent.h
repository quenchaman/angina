#ifndef ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_
#define ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_

#include <string>

#include "enginev2/graphics/sdl/primitives/Texture.h"

#include "enginev2/components/PrimitivesComponent.h"

struct TextureRendererComponent;

class TextureComponent : public PrimitivesComponent<Texture> {
public:
	TextureComponent();

	void loadTexture(const std::string& resourcePath, TextureRendererComponent&);
	void loadTexture(const std::string& resourcePath, TextureRendererComponent&, const Rectangle&);
};

#endif /* ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_ */
