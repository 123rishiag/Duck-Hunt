#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

namespace Wave
{
	enum class WaveType;
	enum class WaveState;
	enum class WaveResult;

	struct WaveConfig;
	class WaveController;

	class WaveService
	{
	private:

		WaveType currentWaveType;
		WaveController* waveController;

	public:
		WaveService();
		virtual ~WaveService();

		void Initialize();
		void Update();

		void LoadWave();
		void HoldWave();

		bool IsGameOver() const;
		void GameOver();

		sf::String GetWaveName() const;
		float GetWaveTimeLeft() const;
		WaveConfig GetWaveConfig(WaveType waveType) const;
		void SetNextWaveType();

		WaveType GetWaveType() const;
		WaveState GetWaveState() const;
		WaveResult GetWaveResult() const;

		void Reset();
	};
}