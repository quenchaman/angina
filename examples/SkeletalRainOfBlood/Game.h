#ifndef SKELETAL_RAIN_OF_BLOOD
#define SKELETAL_RAIN_OF_BLOOD

#include "enginev2/GameEngine.h"

class Game : public GameEngine {
public:
	Game();
	void onStart();
	void onUpdate();
	void handleEvent();

private:
	uint32_t heroSpriteId;
};

#endif // !SKELETAL_RAIN_OF_BLOOD
