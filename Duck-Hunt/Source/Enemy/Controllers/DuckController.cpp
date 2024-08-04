#include "../../Header/Enemy/Controllers/DuckController.h"

namespace Enemy
{
    namespace Controller
    {
        DuckController::DuckController(EnemyType type) : EnemyController(type) { }

        DuckController::~DuckController() { }

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
