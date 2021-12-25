/*
 * Engine.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_ENGINE_H_
#define SDL_GRAPHICS_ENGINE_H_

#include <vector>
#include <string>
#include <map>

struct Window;
union SDL_Event;
struct Renderer;
struct TTF_Font;
struct Texture;

class Engine {
public:
	Engine(std::string appTitle);
	virtual ~Engine();

	void start();
	void loadGameResources(std::vector<std::string> paths);
	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void executeGameLogic() = 0;

	virtual void handleLeftMouseClick() = 0;
private:
	Window* window;
	SDL_Event e;
protected:
    Renderer* renderer;
    bool quit;
    std::map<std::string, Texture*> resources;
    TTF_Font* font;
private:
    void executeDraw();
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
