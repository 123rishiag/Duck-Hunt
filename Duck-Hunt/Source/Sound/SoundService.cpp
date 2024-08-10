#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace Sound
{
	using namespace Global;

	SoundService::SoundService()
	{
		currentSoundIndex = 0;
		soundPool.resize(soundPoolSize); // Adjust the size based on how many simultaneous sounds you expect to play
	}

	SoundService::~SoundService() {	}

	void SoundService::Initialize()
	{
		LoadBackgroundMusicFromFile();
		LoadSoundFromFile();
	}

	void SoundService::LoadBackgroundMusicFromFile()
	{
		if (!backgroundMusic.openFromFile(Config::backgroundMusicPath)) //if this returns true then print error
			printf("Error loading background music file");
	}

	bool SoundService::LoadSoundBuffer(sf::SoundBuffer& buffer, const std::string& filePath)
	{
		if (!buffer.loadFromFile(filePath))
		{
			printf("Error loading sound file: %s\n", filePath.c_str());
			return false;
		}
		return true;
	}

	void SoundService::LoadSoundFromFile()
	{
		LoadSoundBuffer(bufferButtonClick, Config::buttonClickSoundPath);
		LoadSoundBuffer(bufferExplosion, Config::explosionSoundPath);
		LoadSoundBuffer(bulletFire, Config::bulletFireSoundPath);
		LoadSoundBuffer(waveStarted, Config::waveStartSoundPath);
		LoadSoundBuffer(waveEnded, Config::waveEndSoundPath);
	}

	void SoundService::PlaySound(SoundType soundType)
	{
		// If parallel sounds are there, they will be played by different sound buffers stored in soundPool
		sf::Sound& soundEffect = soundPool[currentSoundIndex];
		currentSoundIndex = (currentSoundIndex + 1) % soundPool.size();

		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
			break;
		case SoundType::EXPLOSION:
			soundEffect.setBuffer(bufferExplosion);
			break;
		case SoundType::BULLET_FIRE:
			soundEffect.setBuffer(bulletFire);
			break;
		case SoundType::WAVE_START:
			soundEffect.setBuffer(waveStarted);
			break;
		case SoundType::WAVE_END:
			soundEffect.setBuffer(waveEnded);
			break;
		default:
			printf("Invalid sound type");
			return;
		}
		soundEffect.play();
	}

	void SoundService::PlayBackgroundMusic()
	{
		backgroundMusic.setLoop(true);
		backgroundMusic.setVolume(backgroundMusicVolume);
		backgroundMusic.play();
	}
}