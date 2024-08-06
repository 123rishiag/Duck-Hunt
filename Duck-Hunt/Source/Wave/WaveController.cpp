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
		waveTime = sf::seconds(waveConfig.waveDuration);
	}

	void WaveController::Update()
	{
		if (clock.getElapsedTime() >= waveTime)
		{
			clock.restart();
		}
	}

	void WaveController::UpdateConfig(const WaveConfig& config)
	{
		waveConfig = config;
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