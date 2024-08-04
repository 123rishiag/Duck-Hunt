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
