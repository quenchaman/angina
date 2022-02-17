#ifndef CHESS_GAME_PAGES_LANDINGPAGE_H_
#define CHESS_GAME_PAGES_LANDINGPAGE_H_

#include "sdl/engine/page/Page.h"

struct Renderer;

class LandingPage : public Page {
public:
	LandingPage(Renderer& renderer);

	void onPageLoad();
};

#endif /* CHESS_GAME_PAGES_LANDINGPAGE_H_ */
