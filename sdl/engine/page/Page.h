/*
 * Page.h
 *
 *  Created on: Jan 2, 2022
 *      Author: ubuntu
 */

#ifndef SDL_ENGINE_PAGE_PAGE_H_
#define SDL_ENGINE_PAGE_PAGE_H_

#include <cstdint>
#include <unordered_map>

#include "sdl/engine/buttons/ButtonManager.h"
#include "SDL_ttf.h"

struct Texture;
struct Rect;
struct Object;
struct Renderer;
struct Point;

class Page {
public:
	Page(Renderer& renderer);
	virtual ~Page();

	virtual void draw() = 0;

	void setBackground(Texture& background);

	void addRectangle(int32_t id, Rect& rectangle);
	void addObject(int32_t id, Object& object);
	void addObject(int32_t id, const std::string& resourcePath, Point position);
	void addButton(int32_t id, const std::string& resourcePath, Point position);
	void addText(int32_t id, std::string text);

	ButtonManager buttonManager;
protected:
	std::unordered_map<int32_t, Rect*> rectangles;
	std::unordered_map<int32_t, Object*> objects;
	Texture* _background = nullptr;
private:
	Renderer& _renderer;
	TTF_Font* font;
};

#endif /* SDL_ENGINE_PAGE_PAGE_H_ */
