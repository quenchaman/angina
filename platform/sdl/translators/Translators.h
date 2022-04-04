#ifndef PLATFORM_SDL_TRANSLATORS_TRANSLATORS_H_
#define PLATFORM_SDL_TRANSLATORS_TRANSLATORS_H_

#include "SDL_image.h"

#include "renderer/primitives/Color.h"

namespace Translators {
	inline SDL_Color toSDLColor(Color color) {
		return { color.red, color.green, color.blue, color.alpha };
	}
}


#endif /* PLATFORM_SDL_TRANSLATORS_TRANSLATORS_H_ */
