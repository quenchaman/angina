#ifndef ENGINE_REPOSITORIES_TEXTREPOSITORY_H_
#define ENGINE_REPOSITORIES_TEXTREPOSITORY_H_

#include <unordered_map>

struct Text;

/**
 * Cache for text textures.
 */
class TextRepository {
public:
	TextRepository();
	~TextRepository();

	void add(std::string);

	Text* get(std::string);
private:
	std::unordered_map<std::string, Text*> data;
};

#endif /* ENGINE_REPOSITORIES_TEXTREPOSITORY_H_ */
