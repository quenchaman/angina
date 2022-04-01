#include "ShortSoundsAudioPlayer.h"

#include <SDL_mixer.h>

ShortSoundsAudioPlayer::ShortSoundsAudioPlayer(): sound(nullptr) {
}

bool ShortSoundsAudioPlayer::load(std::string path) {
	freeSound();

	sound = Mix_LoadWAV(path.c_str());

	return sound != nullptr;
}

void ShortSoundsAudioPlayer::play() {
	if (sound == nullptr) {
		return;
	}

	Mix_PlayChannel(-1, sound, 0);
}

void ShortSoundsAudioPlayer::pause() {
	Mix_HaltMusic();
}

void ShortSoundsAudioPlayer::resume() {
	Mix_ResumeMusic();
}

void ShortSoundsAudioPlayer::freeSound() {
	if (sound != nullptr) {
		Mix_FreeChunk(sound);
		sound = nullptr;
	}
}

ShortSoundsAudioPlayer::~ShortSoundsAudioPlayer() {
	freeSound();
}
