#include "../../Header/Enemy/Controllers/DuckController.h"

namespace Enemy
{
    namespace Controller
    {
        DuckController::DuckController(EnemyType type) : EnemyController(type) 
        { 
            SetEnemyHorizontalMovementSpeed(750.0f);
            SetEnemyVerticalMovementSpeed(150.f);
            SetEnemyDeathRadius(100.f);
            SetEnemyDeathScore(100);
        }

        DuckController::~DuckController() { }
    }
}
