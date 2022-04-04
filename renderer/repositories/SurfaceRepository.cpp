#include "SurfaceRepository.h"

#include "platform/sdl/primitives/Surface.h"

SurfaceRepository::SurfaceRepository() {}

void SurfaceRepository::add(const std::string key, Surface& surface) {
	data[key] = &surface;
}

Surface& SurfaceRepository::get(const std::string& key) {
	return *data.at(key);
}

bool SurfaceRepository::exists(const std::string& key) const {
	return data.find(key) != data.end();
}
