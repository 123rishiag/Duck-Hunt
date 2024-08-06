#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;

	GameplayService::GameplayService() { gameplayController = new GameplayController(); }

	GameplayService::~GameplayService() { delete (gameplayController); }

	void GameplayService::Initialize() { gameplayController->Initialize(); }

	void GameplayService::Update() 
	{
		gameplayController->Update();
	}

	void GameplayService::Render() { gameplayController->Render(); }

	void GameplayService::ActivateBackgroundAlpha(bool isActivated)
	{
		gameplayController->ActivateBackgroundAlpha(isActivated);
	}

	void GameplayService::Restart()
	{
		ServiceLocator::GetInstance()->GetWaveService()->Reset();
	}
}