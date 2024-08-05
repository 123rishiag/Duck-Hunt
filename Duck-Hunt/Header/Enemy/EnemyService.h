#pragma once
#include <vector>
#include <unordered_set>
#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class EnemyType;
	enum class HorizontalMovementDirection;
	enum class VerticalMovementDirection;

	class EnemyController;

	class EnemyService
	{
	private:
		std::vector<EnemyController*> enemyList;
		std::vector<EnemyController*> flaggedEnemyList;

		int enemyCount;
		int maxEnemies = 3;

		void UpdateMaxEnemy(int number);
		void ProcessEnemySpawn();
		EnemyType GetRandomEnemyType() const;
		EnemyController* CreateEnemy(EnemyType enemyType) const;

		bool IsValidEnemy(int indexI, std::vector<EnemyController*>& enemyList);

		void DestroyFlaggedEnemies();
		void DestroyEnemyRecursive(sf::Vector2f position, float radius, std::unordered_set<EnemyController*>& enemiesToDestroy);
		void Destroy(bool increaseScore); // function to delete enemy

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		HorizontalMovementDirection GetRandomEnemyHorizontalMovementDirection() const;
		VerticalMovementDirection GetRandomEnemyVerticalMovementDirection() const;
		EnemyController* SpawnEnemy();
		EnemyController* GetCurrentEnemy();
		std::vector<EnemyController*> GetAllEnemies();

		void DestroyEnemy(EnemyController* enemyController, bool increaseScore);
		void DestroyEnemyByPosition(sf::Vector2f position, float radius);

		EnemyType GetEnemyType(EnemyController* enemyController) const;

		void Reset(bool increaseScore);

	};
}