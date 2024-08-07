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
		Reset();
	}

	void WaveController::Update()
	{
		UpdateWaveState();
	}

	void WaveController::UpdateWaveState()
	{
		float deltaTime = ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		stateTime += deltaTime;

		switch (currentWaveState)
		{
		case WaveState::WAVE_BOOT:
			if (stateTime >= waveBootTime)
			{
				currentWaveState = WaveState::WAVE_PLAY;
				ServiceLocator::GetInstance()->GetWaveService()->LoadWave();
				stateTime = 0;
				waveTimeLeft = waveConfig.waveDuration;
			}
			break;

		case WaveState::WAVE_PLAY:
			waveTimeLeft -= deltaTime;
			if (waveTimeLeft < 0)
			{
				waveTimeLeft = 0;
			}
			if (IsWaveWon() || IsWaveLost())
			{
				currentWaveState = WaveState::WAVE_RESULT;
				if (IsWaveWon())
				{
					currentWaveResult = Wave::WaveResult::WAVE_WON;
					ServiceLocator::GetInstance()->GetWaveService()->SetNextWaveType();
				}
				else if (IsWaveLost())
				{
					ServiceLocator::GetInstance()->GetPlayerService()->ReducePlayerHealth(1);
					currentWaveResult = Wave::WaveResult::WAVE_LOST;
				}
				ServiceLocator::GetInstance()->GetWaveService()->HoldWave();
				stateTime = 0;
			}
			break;

		case WaveState::WAVE_RESULT:
			if (stateTime >= waveResultTime)
			{
				currentWaveState = WaveState::WAVE_BOOT;
				stateTime = 0;
				Reset(); // Reset for the next wave
				ServiceLocator::GetInstance()->GetWaveService()->GameOver();
			}
			break;
		}
	}

	void WaveController::UpdateConfig(const WaveConfig& config)
	{
		waveConfig = config;
	}

	sf::String WaveController::GetWaveName() const
	{
		return waveConfig.waveName;
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

		if ((enemyCount > 0 && playerAmmo == 0) || (waveTimeLeft == 0.f))
		{
			return true;
		}
		return false;
	}

	WaveState WaveController::GetWaveState() const 
	{
		return currentWaveState;
	}
	WaveResult WaveController::GetWaveResult() const
	{
		return currentWaveResult;
	}

	void WaveController::Reset()
	{
		currentWaveState = Wave::WaveState::WAVE_BOOT;
		currentWaveResult = Wave::WaveResult::WAVE_UNDECIDED;
		waveTimeLeft = waveConfig.waveDuration;
		stateTime = 0;
	}
}