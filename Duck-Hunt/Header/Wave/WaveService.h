#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Wave/WaveController.h"

namespace Wave
{
	enum class WaveType
	{
		WAVE_1,
		WAVE_2,
	};

	class WaveService
	{
	private:
		std::vector<WaveController*> waveList;
		std::vector<WaveController*> flaggedWaveList;

		WaveType currentWaveType;

		WaveConfig GetWaveConfig(WaveType waveType);
		void DestroyFlaggedWaves();
		void Destroy();

	public:
		WaveService();
		virtual ~WaveService();

		void Initialize();
		void Update();

		void Reset();

		void SpawnWave(WaveType waveType);
		void DestroyWave(WaveController* waveController);
	};
}