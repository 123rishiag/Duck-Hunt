#include "../../Header/Enemy/Controllers/PowerDuckController.h"

namespace Enemy
{
    namespace Controller
    {
        PowerDuckController::PowerDuckController(EnemyType type) : EnemyController(type) { }

        PowerDuckController::~PowerDuckController() { }

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
