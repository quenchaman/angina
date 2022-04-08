#ifndef SDL_COMPONENTS_WINDOW_H_
#define SDL_COMPONENTS_WINDOW_H_

#include <string>

#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"

struct SDL_Window;
struct SDL_Surface;

/**
 * Wrapper around SDL_Window.
 * Manages initialization and destruction of window and it's surface.
 */
class Window {
public:
	Window(std::string title, Point, Dimensions, int32_t flags);
	~Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(Window&&) = delete;
	Window& operator=(Window&&) = delete;

	SDL_Window* getWindow();
	SDL_Surface* getSurface();
private:
	SDL_Window *window;
	SDL_Surface *surface;
};

#endif /* SDL_COMPONENTS_WINDOW_H_ */
