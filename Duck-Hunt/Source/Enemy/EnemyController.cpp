#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;

	EnemyController::EnemyController(EnemyType type)
	{
        std::srand(static_cast<unsigned int>(std::time(nullptr)) + std::rand());

		enemyView = new EnemyView();
		enemyModel = new EnemyModel(type);
	}

	EnemyController::~EnemyController()
	{
		delete (enemyView);
		delete (enemyModel);
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize(GetEnemyHorizontalMovementSpeed(), GetEnemyVerticalMovementSpeed(),
            GetRandomEnemyHorizontalMovementDirection(), GetRandomEnemyVerticalMovementDirection(),
            GetEnemyDeathRadius());
		enemyView->Initialize(this); // we will discuss this soon
	}

	void EnemyController::Update()
	{
		Move();
		enemyView->Update();
	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}

	void EnemyController::Move()
	{
		MoveHorizontal(false);
		MoveVertical(false);
	}

	void EnemyController::Move(bool isHorizontal, bool isRandom)
	{
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

		float newOffset = GetRandomOffset();
		float& previousOffset = isHorizontal ? previousHorizontalOffset : previousVerticalOffset;
		float& offset = isHorizontal ? horizontalOffset : verticalOffset;
		offset = SmoothOffset(previousOffset, newOffset);
		previousOffset = offset;

		float movementSpeed = isHorizontal ? GetEnemyHorizontalMovementSpeed() : GetEnemyVerticalMovementSpeed();
		float delta = (movementSpeed + offset) * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (isHorizontal)
		{
			currentPosition.x += delta * (enemyModel->GetEnemyHorizontalMovementDirection() == HorizontalMovementDirection::LEFT ? -1.0f : 1.0f);

			if (currentPosition.x <= enemyModel->leftMostPosition)
			{
				currentPosition.x = enemyModel->leftMostPosition;
				enemyModel->SetEnemyHorizontalMovementDirection(HorizontalMovementDirection::RIGHT);
				if (isRandom) enemyModel->SetEnemyVerticalMovementDirection(GetRandomEnemyVerticalMovementDirection());
			}
			else if (currentPosition.x >= enemyModel->rightMostPosition)
			{
				currentPosition.x = enemyModel->rightMostPosition;
				enemyModel->SetEnemyHorizontalMovementDirection(HorizontalMovementDirection::LEFT);
				if (isRandom) enemyModel->SetEnemyVerticalMovementDirection(GetRandomEnemyVerticalMovementDirection());
			}
		}
		else
		{
			currentPosition.y += delta * (enemyModel->GetEnemyVerticalMovementDirection() == VerticalMovementDirection::UP ? -1.0f : 1.0f);

			if (currentPosition.y <= enemyModel->upMostPosition)
			{
				currentPosition.y = enemyModel->upMostPosition;
				enemyModel->SetEnemyVerticalMovementDirection(VerticalMovementDirection::DOWN);
				if (isRandom) enemyModel->SetEnemyHorizontalMovementDirection(GetRandomEnemyHorizontalMovementDirection());
			}
			else if (currentPosition.y >= enemyModel->downMostPosition)
			{
				currentPosition.y = enemyModel->downMostPosition;
				enemyModel->SetEnemyVerticalMovementDirection(VerticalMovementDirection::UP);
				if (isRandom) enemyModel->SetEnemyHorizontalMovementDirection(GetRandomEnemyHorizontalMovementDirection());
			}
		}

		enemyModel->SetEnemyPosition(currentPosition);
	}

	void EnemyController::MoveHorizontal(bool isRandomVertical)
	{
		Move(true, isRandomVertical);
	}

	void EnemyController::MoveVertical(bool isRandomHorizontal)
	{
		Move(false, isRandomHorizontal);
	}

    float EnemyController::GetRandomOffset()
    {
        // Generate a random float between -0.5 * factor and 0.5 * factor and scale it up
        return ((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) - 0.5f) * 1000.0f * 1000.0f
            * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
    }

    float EnemyController::SmoothOffset(float currentOffset, float newOffset)
    {
        return currentOffset + smoothingFactor * (newOffset - currentOffset)
            * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
    }

	HorizontalMovementDirection EnemyController::GetRandomEnemyHorizontalMovementDirection() const
	{
		int randomValue = std::rand() % (static_cast<int>(Enemy::HorizontalMovementDirection::RIGHT) + 1);
		return static_cast<Enemy::HorizontalMovementDirection>(randomValue); //cast int to HorizontalMovementDirection enum class
	}

	VerticalMovementDirection EnemyController::GetRandomEnemyVerticalMovementDirection() const
	{
		int randomValue = std::rand() % (static_cast<int>(Enemy::VerticalMovementDirection::DOWN) + 1);
		return static_cast<Enemy::VerticalMovementDirection>(randomValue); //cast int to VerticalMovementDirection enum class
	}

	EnemyType EnemyController::GetEnemyType() const
	{
		return enemyModel->GetEnemyType();
	}

	EnemyState EnemyController::GetEnemyState() const
	{
		return enemyModel->GetEnemyState();
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}

	float EnemyController::GetEnemyHorizontalMovementSpeed() const
	{
		return enemyModel->GetEnemyHorizontalMovementSpeed();
	}

	void EnemyController::SetEnemyHorizontalMovementSpeed(float speed)
	{
		enemyModel->SetEnemyHorizontalMovementSpeed(speed);
	}

	float EnemyController::GetEnemyVerticalMovementSpeed() const
	{
		return enemyModel->GetEnemyVerticalMovementSpeed();
	}

	void EnemyController::SetEnemyVerticalMovementSpeed(float speed)
	{
		enemyModel->SetEnemyVerticalMovementSpeed(speed);
	}

	float EnemyController::GetEnemyDeathRadius() const
	{
		return enemyModel->GetEnemyDeathRadius();
	}

	void EnemyController::SetEnemyDeathRadius(float radius)
	{
		enemyModel->SetEnemyDeathRadius(radius);
	}

	int EnemyController::GetEnemyDeathScore() const
	{
		return enemyModel->GetEnemyDeathScore();
	}

	void EnemyController::SetEnemyDeathScore(int score)
	{
		enemyModel->SetEnemyDeathScore(score);
	}

	void EnemyController::Destroy(bool increaseScore)
	{
		ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this, increaseScore);
	}

}