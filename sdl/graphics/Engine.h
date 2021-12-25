/*
 * Engine.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_ENGINE_H_
#define SDL_GRAPHICS_ENGINE_H_

#include <vector>
#include <cstdint>
#include <string>
#include <unordered_map>

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
	void loadResources(const std::unordered_map<int32_t, std::string>& idToPaths);
	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void executeLogic() = 0;

	virtual void handleLeftMouseClick() = 0;
private:
	Window* window;
	SDL_Event e;
protected:
    Renderer* renderer;
    bool quit;
    std::unordered_map<int32_t, Texture*> resources;
    TTF_Font* font;
private:
    void executeDraw();
};


#endif /* SDL_GRAPHICS_ENGINE_H_ */
