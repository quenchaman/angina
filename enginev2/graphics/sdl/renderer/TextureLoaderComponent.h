#ifndef ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURELOADERCOMPONENT_H_
#define ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURELOADERCOMPONENT_H_

#include <string>

struct TextureRendererComponent;
struct SDL_Texture;

class TextureLoaderComponent {
public:
    void init(TextureRendererComponent&);

    SDL_Texture* loadTexture(const std::string& resourcePath);
private:
    TextureRendererComponent* renderer;
};

#endif /* ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURELOADERCOMPONENT_H_ */
