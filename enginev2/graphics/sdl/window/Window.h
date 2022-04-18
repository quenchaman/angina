#ifndef SDL_COMPONENTS_WINDOW_H_
#define SDL_COMPONENTS_WINDOW_H_

#include <string>

#include "enginev2/graphics/sdl/renderer/Renderer.h"
#include "enginev2/graphics/commons/primitives/Width.h"
#include "enginev2/graphics/commons/primitives/Height.h"

struct SDL_Window;
struct SDL_Surface;

/**
 * Wrapper around SDL_Window.
 * Manages initialization and destruction of window and it's surface.
 */
class Window {
public:
	friend class Renderer;
	Window();
	~Window();

	void init(const std::string& title,
			int32_t xPos,
			int32_t yPos,
			Width width,
			Height height);

	void init(const std::string& title,
				Width width,
				Height height);

	void resize(Width width, Height height);
	void update();
	void clear();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(Window&&) = delete;
	Window& operator=(Window&&) = delete;

	SDL_Window *sdlWindow;
	SDL_Surface *surface;
private:

};

#endif /* SDL_COMPONENTS_WINDOW_H_ */
