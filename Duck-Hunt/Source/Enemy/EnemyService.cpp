#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/Controllers/DuckController.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyService::EnemyService() {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService() { Destroy(true); }

	void EnemyService::Initialize()
	{
		enemyCount = 0; // for the first spawn
	}

	void EnemyService::Update()
	{
		ProcessEnemySpawn();
		for (EnemyController* enemy : enemyList)
			enemy->Update();

		DestroyFlaggedEnemies();
	}

	void EnemyService::Render()
	{
		for (EnemyController* enemy : enemyList)
			enemy->Render();
	}

	void EnemyService::UpdateMaxEnemy(int number)
	{
		maxEnemies = number;
	}

	void EnemyService::ProcessEnemySpawn()
	{
		if (enemyCount < maxEnemies)
		{
			SpawnEnemy(); //spawn
		}
	}

	EnemyController* EnemyService::SpawnEnemy()
	{
		// The base class pointer will be pointing to a child class object
		EnemyController* enemyController = CreateEnemy(GetRandomEnemyType());
		enemyController->Initialize();

		enemyList.push_back(enemyController);
		enemyCount += 1;
		return enemyController;
	}

	EnemyType EnemyService::GetRandomEnemyType() const
	{
		int randomValue = std::rand() % (static_cast<int>(Enemy::EnemyType::POWER_DUCK) + 1);
		return static_cast<Enemy::EnemyType>(randomValue); //cast int to EnemyType enum class
	}

	EnemyController* EnemyService::CreateEnemy(EnemyType enemyType) const
	{
		switch (enemyType)
		{
		case::Enemy::EnemyType::DUCK:
			return new Controller::DuckController(Enemy::EnemyType::DUCK);
		case::Enemy::EnemyType::POWER_DUCK:
			return new Controller::DuckController(Enemy::EnemyType::DUCK);
		}
	}

	void EnemyService::DestroyFlaggedEnemies()
	{
		for (int i = 0; i < flaggedEnemyList.size(); i++)
		{
			delete (flaggedEnemyList[i]);
		}
		flaggedEnemyList.clear();
	}

	// Function to destroy an enemy controller object from the enemy_list vector.
	void EnemyService::DestroyEnemy(EnemyController* enemyController)
	{
		flaggedEnemyList.push_back(enemyController);
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyController), enemyList.end());
	}

	void EnemyService::Destroy(bool increaseScore)
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Destroy();
			if (increaseScore == true) {
				//ServiceLocator::GetInstance()->GetPlayerService()->IncreaseEnemiesKilled(1);
			}
		}
		enemyList.clear();
	}

	void EnemyService::Reset(bool increaseScore)
	{
		Destroy(increaseScore);
		enemyCount = 0;
	}
}