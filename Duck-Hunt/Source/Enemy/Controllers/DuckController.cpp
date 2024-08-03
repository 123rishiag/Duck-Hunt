#include "../../Header/Enemy/Controllers/DuckController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
    using namespace Global;

    namespace Controller
    {
        DuckController::DuckController(EnemyType type) : EnemyController(type) { }

        DuckController::~DuckController() { }

        void DuckController::Move()
        {
            MoveHorizontal();
            MoveVertical();
        }

        void DuckController::MoveHorizontal()
        {
            sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

            switch (enemyModel->GetHorizontalMovementDirection())
            {
            case HorizontalMovementDirection::LEFT:
                currentPosition.x -= horizontalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
                if (currentPosition.x <= enemyModel->leftMostPosition)
                {
                    currentPosition.x = enemyModel->leftMostPosition;
                    enemyModel->SetHorizontalMovementDirection(HorizontalMovementDirection::RIGHT);
                }
                break;

            case HorizontalMovementDirection::RIGHT:
                currentPosition.x += horizontalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
                if (currentPosition.x >= enemyModel->rightMostPosition)
                {
                    currentPosition.x = enemyModel->rightMostPosition;
                    enemyModel->SetHorizontalMovementDirection(HorizontalMovementDirection::LEFT);
                }
                break;
            }

            enemyModel->SetEnemyPosition(currentPosition);
        }

        void DuckController::MoveVertical()
        {
            sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

            switch (enemyModel->GetVerticalMovementDirection())
            {
            case VerticalMovementDirection::UP:
                currentPosition.y -= verticalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
                if (currentPosition.y <= enemyModel->upMostPosition)
                {
                    currentPosition.y = enemyModel->upMostPosition;
                    enemyModel->SetVerticalMovementDirection(VerticalMovementDirection::DOWN);
                }
                break;

            case VerticalMovementDirection::DOWN:
                currentPosition.y += verticalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
                if (currentPosition.y >= enemyModel->downMostPosition)
                {
                    currentPosition.y = enemyModel->downMostPosition;
                    enemyModel->SetVerticalMovementDirection(VerticalMovementDirection::UP);
                }
                break;
            }

            enemyModel->SetEnemyPosition(currentPosition);
        }

        float DuckController::GetEnemyHorizontalMovementSpeed()
        {
            return horizontalMovementSpeed;
        }

        float DuckController::GetEnemyVerticalMovementSpeed()
        {
            return verticalMovementSpeed;
        }

        float DuckController::GetEnemyDeathRadius()
        {
            return enemyDeathRadius;
        }
    }
}