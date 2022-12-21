#ifndef ENGINEV2_COMPONENTS_SURFACECOMPONENT_H_
#define ENGINEV2_COMPONENTS_SURFACECOMPONENT_H_

#include <string>

#include "enginev2/graphics/sdl/primitives/Surface.h"

#include "enginev2/components/PrimitivesComponent.h"

class Window;

class SurfaceComponent : public PrimitivesComponent<Surface> {
public:
	SurfaceComponent();

	void loadSurface(const std::string& pathToResource);
	void loadSurfaceOptim(const std::string& pathToResource, Window&);
};

#endif /* ENGINEV2_COMPONENTS_SURFACECOMPONENT_H_ */
