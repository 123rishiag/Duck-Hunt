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
	}

	bool WaveService::IsGameOver() const
	{
		if (!ServiceLocator::GetInstance()->GetPlayerService()->IsPlayerAlive() || currentWaveType == Wave::WaveType::WAVE_END)
		{
			return true;
		}
		return false;
	}

	void WaveService::GameOver()
	{
		if (IsGameOver())
		{
			// Resetting entities like player health & score when Game is over
			ServiceLocator::GetInstance()->GetPlayerService()->ResetPlayerHealth();
			ServiceLocator::GetInstance()->GetPlayerService()->ResetPlayerScore();
			Reset();
			ServiceLocator::GetInstance()->GetUIService()->ShowMainMenu();
		}	
	}

	// To call the same wave in case of wave loss
	void WaveService::LoadWave()
	{
		WaveConfig waveConfig = GetWaveConfig(currentWaveType);
		ServiceLocator::GetInstance()->GetPlayerService()->Reset(waveConfig.playerPointAmmo, waveConfig.playerAreaAmmo);
		ServiceLocator::GetInstance()->GetEnemyService()->Reset(false, waveConfig.enemyCount);
		ServiceLocator::GetInstance()->GetBulletService()->Reset();
	}

	// To not spawn any entities like enemy & ammo
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
			return WaveConfig("Wave 1", 3, 1, 3, 10.0f);
		case Wave::WaveType::WAVE_2:
			return WaveConfig("Wave 2", 6, 1, 5, 15.0f);
		case Wave::WaveType::WAVE_3:
			return WaveConfig("Wave 3", 8, 1, 7, 20.0f);
		case Wave::WaveType::WAVE_4:
			return WaveConfig("Wave 4", 11, 1, 9, 25.0f);
		case Wave::WaveType::WAVE_5:
			return WaveConfig("Wave 5", 13, 1, 11, 30.0f);
		default:
			return WaveConfig("Wave Default", 0, 0, 0, 0.f);
		}
	}

	void WaveService::SetNextWaveType()
	{
		int waveNumber = static_cast<int>(currentWaveType) + 1;
		currentWaveType = static_cast<WaveType>(waveNumber);
	}

	sf::String WaveService::GetWaveName() const
	{
		return waveController->GetWaveName();
	}

	float WaveService::GetWaveTimeLeft() const
	{
		return waveController->GetWaveTimeLeft();
	}
	
	WaveType WaveService::GetWaveType() const
	{
		return currentWaveType;
	}

	WaveState WaveService::GetWaveState() const
	{
		return waveController->GetWaveState();
	}

	WaveResult WaveService::GetWaveResult() const
	{
		return waveController->GetWaveResult();
	}

	void WaveService::Reset() 
	{
		currentWaveType = Wave::WaveType::WAVE_1;
	}

}