#pragma once
#include <vector>

namespace Enemy
{

	enum class EnemyType;
	class EnemyController;

	class EnemyService
	{
	private:
		std::vector<EnemyController*> enemyList;
		std::vector<EnemyController*> flaggedEnemyList;

		int enemyCount;
		int maxEnemies = 1;

		void UpdateMaxEnemy(int number);
		void ProcessEnemySpawn();
		EnemyType GetRandomEnemyType() const;
		EnemyController* CreateEnemy(EnemyType enemyType) const;
		void DestroyFlaggedEnemies();
		void Destroy(bool increaseScore); // function to delete enemy

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		void Reset(bool increaseScore);

		EnemyController* SpawnEnemy();
		void DestroyEnemy(EnemyController* enemyController);
	};
}