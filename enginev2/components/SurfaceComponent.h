#ifndef ENGINEV2_COMPONENTS_SURFACECOMPONENT_H_
#define ENGINEV2_COMPONENTS_SURFACECOMPONENT_H_

#include <string>
#include <vector>

#include "enginev2/graphics/sdl/primitives/Surface.h"

struct Window;
struct GameEngine;

class SurfaceComponent {
public:
	friend class GameEngine;

	SurfaceComponent();

	void loadSurface(const std::string& pathToResource);
	void loadSurfaceOptim(const std::string& pathToResource, Window&);
private:
	std::vector<Surface> surfaces;
};

#endif /* ENGINEV2_COMPONENTS_SURFACECOMPONENT_H_ */
