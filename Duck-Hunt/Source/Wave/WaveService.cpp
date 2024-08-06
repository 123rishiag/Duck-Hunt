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

		GameOver();
	}

	void WaveService::GameOver()
	{
		if (!ServiceLocator::GetInstance()->GetPlayerService()->IsPlayerAlive() || currentWaveType == Wave::WaveType::WAVE_END)
		{
			// ServiceLocator::GetInstance()->GetEventService()->CloseWindow();
			ServiceLocator::GetInstance()->GetPlayerService()->ResetPlayerHealth();
			Reset();
		}	
	}

	void WaveService::LoadWave()
	{
		WaveConfig waveConfig = GetWaveConfig(currentWaveType);
		ServiceLocator::GetInstance()->GetPlayerService()->Reset(waveConfig.playerPointAmmo, waveConfig.playerAreaAmmo);
		ServiceLocator::GetInstance()->GetEnemyService()->Reset(false, waveConfig.enemyCount);
		ServiceLocator::GetInstance()->GetBulletService()->Reset();
	}

	void WaveService::HoldWave()
	{
		WaveConfig waveConfig = GetWaveConfig(Wave::WaveType::WAVE_END);
		ServiceLocator::GetInstance()->GetPlayerService()->Reset(waveConfig.playerPointAmmo, waveConfig.playerAreaAmmo);
		ServiceLocator::GetInstance()->GetEnemyService()->Reset(false, waveConfig.enemyCount);
		ServiceLocator::GetInstance()->GetBulletService()->Reset();
	}

	WaveConfig WaveService::GetWaveConfig(WaveType waveType) const
	{
		switch (waveType)
		{
		case Wave::WaveType::WAVE_1:
			return WaveConfig(3, 1, 3, 10.0f);
		case Wave::WaveType::WAVE_2:
			return WaveConfig(5, 2, 5, 15.0f);
		default:
			return WaveConfig(0, 0, 0, 0.f);
		}
	}

	void WaveService::SetNextWaveType()
	{
		int waveNumber = static_cast<int>(currentWaveType) + 1;
		currentWaveType = static_cast<WaveType>(waveNumber);
	}

	float WaveService::GetWaveTimeLeft() const
	{
		return waveController->GetWaveTimeLeft();
	}

	void WaveService::Reset() 
	{
		currentWaveType = Wave::WaveType::WAVE_1;
	}

}