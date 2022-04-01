#ifndef PLATFORM_SDL_SERVICES_AUDIOPLAYER_H_
#define PLATFORM_SDL_SERVICES_AUDIOPLAYER_H_

#include <string>

class AudioPlayer {
public:
	AudioPlayer() = default;
	virtual ~AudioPlayer() = default;

	virtual bool load(std::string path) = 0;
	virtual void play() = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;
};

#endif /* PLATFORM_SDL_SERVICES_AUDIOPLAYER_H_ */
