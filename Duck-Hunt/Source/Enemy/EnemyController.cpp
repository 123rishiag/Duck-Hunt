#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
/*
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Sound/SoundService.h"
*/

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	/*
	using namespace Bullet;
	using namespace Player;
	using namespace Sound;
	*/

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
		enemyModel->Initialize(GetEnemyHorizontalMovementSpeed(), GetEnemyVerticalMovementSpeed(), GetEnemyDeathRadius());
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
        MoveHorizontal();
        MoveVertical();
    }

    void EnemyController::MoveHorizontal()
    {
        sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

        float newHorizontalOffset = GetRandomOffset();
        horizontalOffset = SmoothOffset(previousHorizontalOffset, newHorizontalOffset);
        previousHorizontalOffset = horizontalOffset;

        switch (enemyModel->GetHorizontalMovementDirection())
        {
        case HorizontalMovementDirection::LEFT:
            currentPosition.x -= (GetEnemyHorizontalMovementSpeed() + horizontalOffset) * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
            if (currentPosition.x <= enemyModel->leftMostPosition)
            {
                currentPosition.x = enemyModel->leftMostPosition;
                enemyModel->SetHorizontalMovementDirection(HorizontalMovementDirection::RIGHT);
                enemyModel->SetVerticalMovementDirection(ServiceLocator::GetInstance()->GetEnemyService()->GetRandomEnemyVerticalMovementDirection());
            }
            break;

        case HorizontalMovementDirection::RIGHT:
            currentPosition.x += (GetEnemyHorizontalMovementSpeed() + horizontalOffset) * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
            if (currentPosition.x >= enemyModel->rightMostPosition)
            {
                currentPosition.x = enemyModel->rightMostPosition;
                enemyModel->SetHorizontalMovementDirection(HorizontalMovementDirection::LEFT);
                enemyModel->SetVerticalMovementDirection(ServiceLocator::GetInstance()->GetEnemyService()->GetRandomEnemyVerticalMovementDirection());
            }
            break;
        }

        enemyModel->SetEnemyPosition(currentPosition);
    }

    void EnemyController::MoveVertical()
    {
        sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

        float newVerticalOffset = GetRandomOffset();
        verticalOffset = SmoothOffset(previousVerticalOffset, newVerticalOffset);
        previousVerticalOffset = verticalOffset;

        switch (enemyModel->GetVerticalMovementDirection())
        {
        case VerticalMovementDirection::UP:
            currentPosition.y -= (GetEnemyVerticalMovementSpeed() + verticalOffset) * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
            if (currentPosition.y <= enemyModel->upMostPosition)
            {
                currentPosition.y = enemyModel->upMostPosition;
                enemyModel->SetHorizontalMovementDirection(ServiceLocator::GetInstance()->GetEnemyService()->GetRandomEnemyHorizontalMovementDirection());
                enemyModel->SetVerticalMovementDirection(VerticalMovementDirection::DOWN);
            }
            break;

        case VerticalMovementDirection::DOWN:
            currentPosition.y += (GetEnemyVerticalMovementSpeed() + verticalOffset) * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
            if (currentPosition.y >= enemyModel->downMostPosition)
            {
                currentPosition.y = enemyModel->downMostPosition;
                enemyModel->SetHorizontalMovementDirection(ServiceLocator::GetInstance()->GetEnemyService()->GetRandomEnemyHorizontalMovementDirection());
                enemyModel->SetVerticalMovementDirection(VerticalMovementDirection::UP);
            }
            break;
        }

        enemyModel->SetEnemyPosition(currentPosition);
    }

    float EnemyController::GetRandomOffset()
    {
        // Generate a random float between -0.5 and 0.5 and scale it up
        return ((static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) - 0.5f) * 1000.0f * 1000.0f
            * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
    }

    float EnemyController::SmoothOffset(float currentOffset, float newOffset)
    {
        return currentOffset + smoothingFactor * (newOffset - currentOffset)
            * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
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

	void EnemyController::Destroy(bool increaseScore)
	{
		ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this, increaseScore);
	}

}