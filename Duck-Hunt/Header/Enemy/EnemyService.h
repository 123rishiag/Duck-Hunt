#pragma once
#include <vector><
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
		void DestroyFlaggedEnemies();
		void Destroy(bool increaseScore); // function to delete enemy

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		void Reset(bool increaseScore);

		HorizontalMovementDirection GetRandomEnemyHorizontalMovementDirection() const;
		VerticalMovementDirection GetRandomEnemyVerticalMovementDirection() const;
		EnemyController* SpawnEnemy();
		void DestroyEnemy(EnemyController* enemyController);
		void DestroyEnemyByPosition(sf::Vector2f position, float radius);
	};
}