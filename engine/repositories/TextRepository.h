#ifndef ENGINE_REPOSITORIES_TEXTREPOSITORY_H_
#define ENGINE_REPOSITORIES_TEXTREPOSITORY_H_

#include <unordered_map>

struct Text;
struct Font;
struct GraphicsFactory;

/**
 * Cache for text textures.
 * TODO: Cap this storage to some sensible max size.
 */
class TextRepository {
public:
	TextRepository(GraphicsFactory&, Font&);
	~TextRepository();

	Text* get(std::string);
	void deleteJustKey(std::string&);
private:
	GraphicsFactory &gFactory;
	Font &font;

	std::unordered_map<std::string, Text*> data;
};

#endif /* ENGINE_REPOSITORIES_TEXTREPOSITORY_H_ */
