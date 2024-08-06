#include "../../Header/Wave/WaveSystem.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Wave
{
	using namespace Global;

	WaveSystem::WaveSystem(const WaveSystemConfig& config)
	{
		waveSystemConfig = config;
	}

	WaveSystem::~WaveSystem() { }

	void WaveSystem::Initialize()
	{
		waveTime = sf::seconds(waveSystemConfig.waveDuration);
	}

	void WaveSystem::Update()
	{
		if (clock.getElapsedTime() >= waveTime)
		{
			Destroy();
			clock.restart();
		}
	}

	void WaveSystem::Destroy()
	{
		ServiceLocator::GetInstance()->GetWaveService()->DestroyWaveSystem(this);
	}
}