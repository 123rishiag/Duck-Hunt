#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Wave/WaveSystem.h"

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
		std::vector<WaveSystem*> waveSystemList;
		std::vector<WaveSystem*> flaggedWaveSystemList;

		WaveType currentWaveType;

		WaveSystemConfig GetWaveSystemConfig(WaveType waveType);
		void DestroyFlaggedWaveSystem();
		void Destroy();

	public:
		WaveService();
		virtual ~WaveService();

		void Initialize();
		void Update();

		void Reset();

		void SpawnWaveSystem(WaveType waveType);
		void DestroyWaveSystem(WaveSystem* waveSystem);
	};
}