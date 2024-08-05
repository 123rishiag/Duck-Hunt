#include "../../Header/Enemy/Controllers/PowerDuckController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
    using namespace Global;

    namespace Controller
    {
        PowerDuckController::PowerDuckController(EnemyType type) : EnemyController(type) { }

        PowerDuckController::~PowerDuckController() { }

        void PowerDuckController::Move()
        {
            MoveHorizontal();
            MoveVertical();
        }

        void PowerDuckController::MoveHorizontal()
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

        void PowerDuckController::MoveVertical()
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

        float PowerDuckController::GetEnemyHorizontalMovementSpeed()
        {
            return horizontalMovementSpeed;
        }

        float PowerDuckController::GetEnemyVerticalMovementSpeed()
        {
            return verticalMovementSpeed;
        }

        float PowerDuckController::GetEnemyDeathRadius()
        {
            return enemyDeathRadius;
        }

        int PowerDuckController::GetEnemyDeathScore() {
            return enemyDeathScore;
        }
    }
}
