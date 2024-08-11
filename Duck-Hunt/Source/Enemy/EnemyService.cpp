#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/Controllers/DuckController.h"
#include "../../Header/Enemy/Controllers/PowerDuckController.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Sound/SoundService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Sound;

	EnemyService::EnemyService() {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService() { Destroy(false); }

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

	void EnemyService::UpdateMaxEnemy(int maxEnemyCount)
	{
		maxEnemies = maxEnemyCount;
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
			return new Controller::PowerDuckController(Enemy::EnemyType::POWER_DUCK);
		default:
			return nullptr;
		}
	}

	bool EnemyService::IsValidEnemy(int index, std::vector<EnemyController*>& enemyList)
	{
		return index >= 0 && index < enemyList.size() && enemyList[index] != nullptr;
	}

	void EnemyService::DestroyFlaggedEnemies()
	{
		for (auto& enemy : flaggedEnemyList)
		{
			delete (enemy);
		}
		flaggedEnemyList.clear();
	}

	// Function to destroy an enemy controller object from the enemy_list vector.
	void EnemyService::DestroyEnemy(EnemyController* enemyController, bool increaseScore)
	{
		if (std::find(flaggedEnemyList.begin(), flaggedEnemyList.end(), enemyController) == flaggedEnemyList.end())
		{
			flaggedEnemyList.push_back(enemyController);
			enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyController), enemyList.end());
		}
		if (increaseScore == true) {
			ServiceLocator::GetInstance()->GetPlayerService()->IncreasePlayerScore(enemyController->GetEnemyDeathScore());
			ServiceLocator::GetInstance()->GetAnimationService()->SpawnAnimation(enemyController->GetEnemyPosition(),
				Animation::AnimationType::EXPLOSION, enemyController->GetEnemyDeathRadius());
			ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::EXPLOSION);
		}
	}

	EnemyController* EnemyService::GetCurrentEnemy()
	{
		if (IsValidEnemy(0, enemyList))
		{
			return enemyList[0];
		}
		return nullptr;
	}

	std::vector<EnemyController*> EnemyService::GetAllEnemies()
	{
		return enemyList;
	}


	int EnemyService::GetEnemiesCount() const
	{
		return static_cast<int>(enemyList.size());;
	}

	// Recursive function to flag enemies for destruction
	void EnemyService::DestroyEnemyRecursive(sf::Vector2f position, float radius, std::unordered_set<EnemyController*>& enemiesToDestroy)
	{
		for (auto& enemy : enemyList)
		{
			if (enemiesToDestroy.find(enemy) != enemiesToDestroy.end())
				continue;

			float distance = std::sqrt(std::pow(enemy->GetEnemyPosition().x - position.x, 2) +
				std::pow(enemy->GetEnemyPosition().y - position.y, 2));

			if (distance <= radius)
			{
				enemiesToDestroy.insert(enemy);
				DestroyEnemyRecursive(enemy->GetEnemyPosition(), enemy->GetEnemyDeathRadius(), enemiesToDestroy);
			}
		}
	}

	// Function to destroy an enemy by position from the enemy_list vector.
	void EnemyService::DestroyEnemyByPosition(sf::Vector2f position, float bulletRadius)
	{
		std::unordered_set<EnemyController*> enemiesToDestroy;

		// Start the recursive destruction process
		DestroyEnemyRecursive(position, bulletRadius, enemiesToDestroy);

		// Flag all selected enemies for destruction
		for (auto& enemy : enemiesToDestroy)
		{
			enemy->Destroy(true);
		}
	}

	void EnemyService::Destroy(bool increaseScore)
	{
		for (auto enemy : enemyList)
		{
			enemy->Destroy(increaseScore);
		}
		enemyList.clear();
	}

	EnemyType EnemyService::GetEnemyType(EnemyController* enemyController) const
	{
		return enemyController->GetEnemyType();
	}

	void EnemyService::Reset(bool increaseScore, int maxEnemyCount)
	{
		enemyCount = 0;
		UpdateMaxEnemy(maxEnemyCount);
		Destroy(increaseScore);
	}

}