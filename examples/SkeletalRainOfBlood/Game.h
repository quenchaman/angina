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
	void handleCollisions(std::vector<std::pair<ID, ID>>) override;

private:
	std::shared_ptr<Texture> heroFacingLeft;
	DIRECTION_STATE dir = DIRECTION_STATE::RIGHT;
	ID paddleId;
	ID ballId;
	float paddleSpeed;
};

#endif // !SKELETAL_RAIN_OF_BLOOD
