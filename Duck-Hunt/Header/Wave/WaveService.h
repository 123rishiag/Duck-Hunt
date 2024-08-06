#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

namespace Wave
{
	enum class WaveType;
	struct WaveConfig;
	class WaveController;

	class WaveService
	{
	private:

		WaveType currentWaveType;
		WaveController* waveController;

		void GameOver();

	public:
		WaveService();
		virtual ~WaveService();

		void Initialize();
		void Update();

		void LoadWave();
		void HoldWave();

		float GetWaveTimeLeft() const;
		WaveConfig GetWaveConfig(WaveType waveType) const;
		void SetNextWaveType();

		void Reset();
	};
}