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
	~Page();

	void loadResources(const std::unordered_map<int32_t, std::string>& idToPaths);
	void loadText(const std::unordered_map<int32_t, std::string>& idToTexts);
	void loadButtons(const std::unordered_map<int32_t, std::string>& idToPaths);
	void addRectangle(int32_t id, Rect& rectangle);
	void addObject(int32_t id, Object& object);
	void setBackground(Texture& background);
	void draw();

	void addObject(int32_t id, const std::string& resourcePath, Point position);
	void addButton(int32_t id, const std::string& resourcePath, Point position);

	ButtonManager buttonManager;
private:
	std::unordered_map<int32_t, Rect*> rectangles;
	std::unordered_map<int32_t, Object*> objects;
	Renderer& _renderer;
	Texture* _background = nullptr;
	TTF_Font* font;
};

#endif /* SDL_ENGINE_PAGE_PAGE_H_ */
