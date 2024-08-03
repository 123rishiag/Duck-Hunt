#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type)
	{
		enemyType = type;
	}

	EnemyModel::~EnemyModel() { }

	void EnemyModel::Initialize(float hSpeed, float ySpeed, float radius)
	{
		enemyPosition = referencePosition;
		enemyDeathRadius = radius;
		enemyState = EnemyState::ALIVE;
		horizontalMovementDirection = HorizontalMovementDirection::RIGHT;
		verticalMovementDirection = VerticalMovementDirection::UP;
	}

	sf::Vector2f EnemyModel::GetReferencePosition() const
	{
		return referencePosition;
	}

	void EnemyModel::SetReferencePosition(sf::Vector2f position)
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

	HorizontalMovementDirection EnemyModel::GetHorizontalMovementDirection() const
	{
		return horizontalMovementDirection;
	}

	void EnemyModel::SetHorizontalMovementDirection(HorizontalMovementDirection direction)
	{
		horizontalMovementDirection = direction;
	}

	VerticalMovementDirection EnemyModel::GetVerticalMovementDirection() const
	{
		return verticalMovementDirection;
	}

	void EnemyModel::SetVerticalMovementDirection(VerticalMovementDirection direction)
	{
		verticalMovementDirection = direction;
	}

	float EnemyModel::GetHorizontalMovementSpeed() const
	{
		return horizontalMovementSpeed;
	}

	void EnemyModel::SetHorizontalMovementSpeed(float speed)
	{
		horizontalMovementSpeed = speed;
	}

	float EnemyModel::GetVerticalMovementSpeed() const
	{
		return verticalMovementSpeed;
	}

	void EnemyModel::SetVerticalMovementSpeed(float speed)
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

}