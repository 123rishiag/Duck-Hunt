#pragma once
#include "SFML/Audio.hpp"
#include <vector>

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		EXPLOSION,
		BULLET_FIRE,
		WAVE_START,
		WAVE_END,
	};

	class SoundService
	{
	private:
		const int backgroundMusicVolume = 30;
		const int soundPoolSize = 10; // Size of the pool to store sound for parallel play

		sf::Music backgroundMusic;  // Holds background music

		std::vector<sf::Sound> soundPool; // To store all sound buffers to play parallel sounds
		int currentSoundIndex;

		sf::Sound soundEffect; // Holds the current sound from soundPool

		sf::SoundBuffer bufferButtonClick;
		sf::SoundBuffer bufferExplosion;
		sf::SoundBuffer bulletFire;
		sf::SoundBuffer waveStarted;
		sf::SoundBuffer waveEnded;

		void LoadBackgroundMusicFromFile(); // To Load Background Music
		void LoadSoundFromFile(); // To Load Other Sound Files

	public:
		SoundService();
		~SoundService();

		void Initialize();

		void PlayBackgroundMusic(); // To Play Background Music
		void PlaySound(SoundType soundType); // To Play Other Sound Files
	};
}