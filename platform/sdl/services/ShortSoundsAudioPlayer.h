#ifndef PLATFORM_SDL_SERVICES_SHORTSOUNDSAUDIOPLAYER_H_
#define PLATFORM_SDL_SERVICES_SHORTSOUNDSAUDIOPLAYER_H_

#include "platform/sdl/services/AudioPlayer.h"

struct Mix_Chunk;

class ShortSoundsAudioPlayer : public AudioPlayer {
public:
	ShortSoundsAudioPlayer();
	~ShortSoundsAudioPlayer();

	/*
	 * For now it will load just .wav files for simplicity.
	 */
	bool load(std::string path);
	void play();
	void pause();
	void resume();
private:
	Mix_Chunk* sound;

	void freeSound();
};

#endif /* PLATFORM_SDL_SERVICES_SHORTSOUNDSAUDIOPLAYER_H_ */
