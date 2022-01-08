/*
 * LandingPage.h
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_PAGES_LANDINGPAGE_H_
#define CHESS_GAME_PAGES_LANDINGPAGE_H_

#include "sdl/engine/page/Page.h"

struct Renderer;

class LandingPage : public Page {
public:
	LandingPage(Renderer& renderer);
	~LandingPage() = default;

	void draw();
	void onPageLoad();
	void onPageUnload();
};

#endif /* CHESS_GAME_PAGES_LANDINGPAGE_H_ */
