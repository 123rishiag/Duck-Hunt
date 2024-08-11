#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyModel::EnemyModel(EnemyType type)
	{
		enemyType = type;
	}

	EnemyModel::~EnemyModel() { }

	void EnemyModel::Initialize(float hSpeed, float ySpeed,
		HorizontalMovementDirection hMoveDirection, VerticalMovementDirection vMoveDirection,
		float radius)
	{
		enemyState = EnemyState::ALIVE;
		enemyPosition = sf::Vector2f(static_cast<int>(leftMostPosition) + (std::rand() % (static_cast<int>(rightMostPosition) - static_cast<int>(leftMostPosition) + 1)) , downMostPosition);
		horizontalMovementDirection = hMoveDirection;
		verticalMovementDirection = vMoveDirection;
		enemyDeathRadius = radius;
	}

	sf::Vector2f EnemyModel::GetEnemyReferencePosition() const
	{
		return referencePosition;
	}

	void EnemyModel::SetEnemyReferencePosition(sf::Vector2f position)
	{
		referencePosition = position;
	}

	sf::Vector2f EnemyModel::GetEnemyPosition() const
	{
		return enemyPosition;
	}

	void EnemyModel::SetEnemyPosition(sf::Vector2f position)
	{
		enemyPosition = position;
	}

	EnemyState EnemyModel::GetEnemyState() const
	{
		return enemyState;
	}

	void EnemyModel::SetEnemyState(EnemyState state)
	{
		enemyState = state;
	}

	EnemyType EnemyModel::GetEnemyType() const
	{
		return enemyType;
	}

	void EnemyModel::SetEnemyType(EnemyType type)
	{
		enemyType = type;
	}

	HorizontalMovementDirection EnemyModel::GetEnemyHorizontalMovementDirection() const
	{
		return horizontalMovementDirection;
	}

	void EnemyModel::SetEnemyHorizontalMovementDirection(HorizontalMovementDirection direction)
	{
		horizontalMovementDirection = direction;
	}

	VerticalMovementDirection EnemyModel::GetEnemyVerticalMovementDirection() const
	{
		return verticalMovementDirection;
	}

	void EnemyModel::SetEnemyVerticalMovementDirection(VerticalMovementDirection direction)
	{
		verticalMovementDirection = direction;
	}

	float EnemyModel::GetEnemyHorizontalMovementSpeed() const
	{
		return horizontalMovementSpeed;
	}

	void EnemyModel::SetEnemyHorizontalMovementSpeed(float speed)
	{
		horizontalMovementSpeed = speed;
	}

	float EnemyModel::GetEnemyVerticalMovementSpeed() const
	{
		return verticalMovementSpeed;
	}

	void EnemyModel::SetEnemyVerticalMovementSpeed(float speed)
	{
		verticalMovementSpeed = speed;
	}

	float EnemyModel::GetEnemyDeathRadius() const
	{
		return enemyDeathRadius;
	}

	void EnemyModel::SetEnemyDeathRadius(float radius)
	{
		enemyDeathRadius = radius;
	}

	int EnemyModel::GetEnemyDeathScore() const
	{
		return enemyDeathScore;
	}

	void EnemyModel::SetEnemyDeathScore(int score)
	{
		enemyDeathScore = score;
	}

}