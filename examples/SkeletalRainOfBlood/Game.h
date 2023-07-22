#ifndef SKELETAL_RAIN_OF_BLOOD
#define SKELETAL_RAIN_OF_BLOOD
#include <memory>

#include "enginev2/GameEngine.h"
#include "enginev2/graphics/sdl/primitives/Texture.h"
#include "enginev2/models/GameObject.h"

enum class DIRECTION_STATE {
	RIGHT,
	LEFT
};

class Game : public GameEngine {
public:
	Game();
	void onStart();
	void onUpdate();
	void handleEvent();

private:
	std::shared_ptr<Texture> heroFacingLeft;
	std::shared_ptr<Texture> paddleTexture;
	DIRECTION_STATE dir = DIRECTION_STATE::RIGHT;
	GameObject* paddle;
};

#endif // !SKELETAL_RAIN_OF_BLOOD
