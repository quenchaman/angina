#ifndef ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_
#define ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_

#include <cstdint>
#include <string>

#include "enginev2/graphics/sdl/primitives/Texture.h"

#include "enginev2/components/PrimitivesComponent.h"

class TextureComponent : public PrimitivesComponent<Texture> {
public:
	void init(std::shared_ptr<TextureRendererComponent>);
	Texture& load(const std::string& pathToTextureFile);
	/*void loadSpriteTexture(const std::string& resourcePath, const Rectangle& clip);
	void loadTexture(const std::string& resourcePath, const Rectangle& viewPort);*/

	//Texture& getTexture(int32_t id);
private:
	std::shared_ptr<TextureRendererComponent> rendererPtr;
};

#endif /* ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_ */
