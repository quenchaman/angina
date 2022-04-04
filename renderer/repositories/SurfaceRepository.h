#ifndef ENGINE_REPOSITORIES_SURFACEREPOSITORY_H_
#define ENGINE_REPOSITORIES_SURFACEREPOSITORY_H_

#include <string>
#include <unordered_map>

struct Surface;

/*
 * Cache for CPU 2D primitive.
 *
 * TODO: Think about providing a method to clean specific or all surfaces once we will no longer create new textures out of them.
 * For example, in the game of chess we create the pieces and rarely create new ones, so we can clean the surfaces so they don't
 * hang out in memory too much.
 * In the case of a RTS or RPG game, we will very often have creation of the same types of monsters, items etc. so it is good idea to
 * keep the surface in handy to avoid a costly resource load during runtime.
 */
class SurfaceRepository {
public:
	SurfaceRepository();

	void add(const std::string key, Surface&);
	Surface& get(const std::string& key);
	bool exists(const std::string& key) const;
private:
	std::unordered_map<std::string, Surface*> data;
};

#endif /* ENGINE_REPOSITORIES_SURFACEREPOSITORY_H_ */
