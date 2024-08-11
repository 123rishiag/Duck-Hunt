#include "../../Header/Enemy/Controllers/DuckController.h"

namespace Enemy
{
    namespace Controller
    {
        DuckController::DuckController(EnemyType type) : EnemyController(type) 
        { 
            horizontalMovementSpeed = 750.0f;
            verticalMovementSpeed = 150.f;
            enemyDeathRadius = 100.f;
            enemyDeathScore = 100;
        }

        DuckController::~DuckController() { }
    }
}
