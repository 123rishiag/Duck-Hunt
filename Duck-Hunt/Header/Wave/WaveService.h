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

		void ProcessWave();
		void LoadWave();

		WaveConfig GetWaveConfig(WaveType waveType) const;
		WaveType GetNextWaveType(WaveType waveType) const;

	public:
		WaveService();
		virtual ~WaveService();

		void Initialize();
		void Update();

		float GetWaveTimeLeft() const;

		void Reset();
	};
}