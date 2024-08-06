#include "../../Header/Wave/WaveService.h"
#include "../../Header/Wave/WaveSystemConfig.h"

namespace Wave
{
	WaveService::WaveService() { }

	WaveService::~WaveService() { Destroy(); }

	void WaveService::Initialize() 
	{ 
		currentWaveType = Wave::WaveType::WAVE_1;
	}

	void WaveService::Update()
	{
		for (WaveSystem* waveSystem : waveSystemList)
			waveSystem->Update();

		DestroyFlaggedWaveSystem();
	}

	void WaveService::SpawnWaveSystem(WaveType waveType)
	{
		WaveSystem* waveSystem = new WaveSystem(GetWaveSystemConfig(waveType));
		waveSystem->Initialize();
		waveSystemList.push_back(waveSystem);
	}

	void WaveService::DestroyWaveSystem(WaveSystem* waveSystem)
	{
		flaggedWaveSystemList.push_back(waveSystem);
		waveSystemList.erase(std::remove(waveSystemList.begin(), waveSystemList.end(), waveSystem), waveSystemList.end());
	}

	WaveSystemConfig WaveService::GetWaveSystemConfig(WaveType waveType)
	{
		switch (waveType)
		{
		case Wave::WaveType::WAVE_1:
			return WaveSystemConfig(3, 1, 3, 20.0f);
		case Wave::WaveType::WAVE_2:
			return WaveSystemConfig(5, 2, 5, 30.0f);
		}
	}

	void WaveService::DestroyFlaggedWaveSystem()
	{
		for (WaveSystem* waveSystem : flaggedWaveSystemList)
			delete (waveSystem);

		flaggedWaveSystemList.clear();
	}

	void WaveService::Reset() { Destroy(); }

	void WaveService::Destroy()
	{
		for (WaveSystem* waveSystem : waveSystemList)
			delete (waveSystem);
	}
}