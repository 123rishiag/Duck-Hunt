#include "../../Header/Wave/WaveService.h"
#include "../../Header/Wave/WaveConfig.h"
#include "../../Header/Wave/WaveController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Wave
{
	using namespace Global;

	WaveService::WaveService()
	{
		Reset();
		waveController = new WaveController(GetWaveConfig(currentWaveType));
	}

	WaveService::~WaveService() 
	{ 
		delete (waveController);
	}

	void WaveService::Initialize() 
	{ 
		waveController->Initialize();
	}

	void WaveService::Update()
	{
		waveController->Update();
		waveController->UpdateConfig(GetWaveConfig(currentWaveType));
		ProcessWave();
	}

	void WaveService::ProcessWave()
	{
		if (waveController->IsWaveWon()) 
		{
			LoadWave();
			currentWaveType = GetNextWaveType(currentWaveType);
		}
		
		if (waveController->IsWaveLost())
		{
			ServiceLocator::GetInstance()->GetPlayerService()->ReducePlayerHealth(1);
			LoadWave();
		}
	}

	void WaveService::LoadWave()
	{
		WaveConfig waveConfig = GetWaveConfig(currentWaveType);
		ServiceLocator::GetInstance()->GetPlayerService()->Reset(waveConfig.playerPointAmmo, waveConfig.playerAreaAmmo);
		ServiceLocator::GetInstance()->GetEnemyService()->Reset(false, waveConfig.enemyCount);
		ServiceLocator::GetInstance()->GetBulletService()->Reset();
	}

	WaveConfig WaveService::GetWaveConfig(WaveType waveType) const
	{
		switch (waveType)
		{
		case Wave::WaveType::WAVE_1:
			return WaveConfig(3, 1, 3, 20.0f);
		case Wave::WaveType::WAVE_2:
			return WaveConfig(5, 2, 5, 2.0f);
		default:
			return WaveConfig(0, 0, 0, 0.f);
		}
	}

	WaveType WaveService::GetNextWaveType(WaveType waveType) const
	{
		int waveNumber = static_cast<int>(waveType) + 1;
		if (waveNumber >= static_cast<int>(WaveType::WAVE_END)) {
			waveNumber = 0;  // Wrap around to the first state
		}
		return static_cast<WaveType>(waveNumber);
	}

	void WaveService::Reset() 
	{ 
		currentWaveType = Wave::WaveType::WAVE_1;
	}

}