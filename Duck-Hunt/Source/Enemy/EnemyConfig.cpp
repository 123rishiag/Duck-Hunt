#include"../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	const sf::String EnemyConfig::duckTexturePath = "assets/textures/duck.png";
	const sf::String EnemyConfig::powerDuckTexturePath = "assets/textures/power_duck.png";

	const sf::String EnemyConfig::GetEnemyTexturePath(EnemyType enemyType)
	{
		switch (enemyType)
		{
		case::Enemy::EnemyType::DUCK:
			return EnemyConfig::duckTexturePath;
		case::Enemy::EnemyType::POWER_DUCK:
			return EnemyConfig::powerDuckTexturePath;
		}
	}
}