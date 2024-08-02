#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;
	/*
	using namespace Player;
	using namespace Enemy;
	using namespace Element;
	using namespace Bullet;
	*/

	GameplayService::GameplayService() { gameplayController = new GameplayController(); }

	GameplayService::~GameplayService() { delete (gameplayController); }

	void GameplayService::Initialize() { gameplayController->Initialize(); }

	void GameplayService::Update() { gameplayController->Update(); }

	void GameplayService::Render() { gameplayController->Render(); }

	void GameplayService::Restart()
	{
		/*
		ServiceLocator::GetInstance()->GetPlayerService()->Reset();
		ServiceLocator::GetInstance()->GetEnemyService()->Reset(false);
		ServiceLocator::GetInstance()->GetBulletService()->Reset();
		ServiceLocator::GetInstance()->GetElementService()->Reset();
		*/
	}
}