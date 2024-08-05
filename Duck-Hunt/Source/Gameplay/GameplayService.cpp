#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;

	GameplayService::GameplayService() { gameplayController = new GameplayController(); }

	GameplayService::~GameplayService() { delete (gameplayController); }

	void GameplayService::Initialize() { gameplayController->Initialize(); }

	void GameplayService::Update() 
	{
		gameplayController->Update();

		int playerHealth = 0;
		playerHealth += ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerHealth();

		int playerAmmo = 0;
		playerAmmo += ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerPointAmmo();
		playerAmmo += ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerAreaAmmo();
		
		int enemyCount = 0;
		enemyCount += ServiceLocator::GetInstance()->GetEnemyService()->GetEnemiesCount();

		if (playerHealth == 0)
		{
			ServiceLocator::GetInstance()->GetEventService()->CloseWindow();
		}
		else if (enemyCount > 0 && playerAmmo == 0)
		{
			ServiceLocator::GetInstance()->GetPlayerService()->ReducePlayerHealth(1);
			Restart();
		}
		else if(enemyCount == 0)
		{
			Restart();
		}
		else
		{

		}
	}

	void GameplayService::Render() { gameplayController->Render(); }

	void GameplayService::Restart()
	{
		ServiceLocator::GetInstance()->GetPlayerService()->Reset(3, 2);
		ServiceLocator::GetInstance()->GetEnemyService()->Reset(false, 3);
		ServiceLocator::GetInstance()->GetBulletService()->Reset();
	}
}