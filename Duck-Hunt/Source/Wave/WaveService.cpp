#include "../../Header/Wave/WaveService.h"
#include "../../Header/Wave/WaveConfig.h"

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
		for (WaveController* waveController : waveList)
			waveController->Update();

		DestroyFlaggedWaves();
	}

	void WaveService::SpawnWave(WaveType waveType)
	{
		WaveController* waveController = new WaveController(GetWaveConfig(waveType));
		waveController->Initialize();
		waveList.push_back(waveController);
	}

	void WaveService::DestroyWave(WaveController* waveController)
	{
		flaggedWaveList.push_back(waveController);
		waveList.erase(std::remove(waveList.begin(), waveList.end(), waveController), waveList.end());
	}

	WaveConfig WaveService::GetWaveConfig(WaveType waveType)
	{
		switch (waveType)
		{
		case Wave::WaveType::WAVE_1:
			return WaveConfig(3, 1, 3, 20.0f);
		case Wave::WaveType::WAVE_2:
			return WaveConfig(5, 2, 5, 30.0f);
		}
	}

	void WaveService::DestroyFlaggedWaves()
	{
		for (WaveController* waveController : flaggedWaveList)
			delete (waveController);

		flaggedWaveList.clear();
	}

	void WaveService::Reset() { Destroy(); }

	void WaveService::Destroy()
	{
		for (WaveController* waveController : waveList)
			delete (waveController);
	}
}