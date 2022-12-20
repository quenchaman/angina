#ifndef ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURELOADERCOMPONENT_H_
#define ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURELOADERCOMPONENT_H_

#include <string>
#include <memory>

#include "SDL_image.h"

struct TextureRendererComponent;

namespace TextureLoaderComponent {
    std::shared_ptr<SDL_Texture> loadTexture(TextureRendererComponent&, const std::string& resourcePath);
};

#endif /* ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURELOADERCOMPONENT_H_ */
