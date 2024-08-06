#include "../../Header/Wave/WaveController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Wave
{
	using namespace Global;

	WaveController::WaveController(const WaveConfig& config)
	{
		waveConfig = config;
	}

	WaveController::~WaveController() {	}

	void WaveController::Initialize()
	{
		waveTimeLeft = waveConfig.waveDuration;
	}

	void WaveController::Update()
	{
		waveTimeLeft -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		if (waveTimeLeft < 0)
		{
			waveTimeLeft = 0;
		}
	}

	void WaveController::UpdateConfig(const WaveConfig& config)
	{
		waveConfig = config;
	}

	float WaveController::GetWaveTimeLeft() const
	{
		return waveTimeLeft;
	}

	void WaveController::SetWaveTimeLeft()
	{
		waveTimeLeft = waveConfig.waveDuration;
	}

	bool WaveController::IsWaveWon() const
	{
		int enemyCount = 0;
		enemyCount += ServiceLocator::GetInstance()->GetEnemyService()->GetEnemiesCount();

		if (enemyCount == 0)
		{
			return true;
		}
		return false;
	}

	bool WaveController::IsWaveLost() const
	{
		int playerAmmo = 0;
		playerAmmo += ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerPointAmmo();
		playerAmmo += ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerAreaAmmo();

		int enemyCount = 0;
		enemyCount += ServiceLocator::GetInstance()->GetEnemyService()->GetEnemiesCount();

		if (enemyCount > 0 && playerAmmo == 0)
		{
			return true;
		}
		return false;
	}
}