#include "../../Header/Enemy/Controllers/PowerDuckController.h"

namespace Enemy
{
    namespace Controller
    {
        PowerDuckController::PowerDuckController(EnemyType type) : EnemyController(type) 
        { 
            SetEnemyHorizontalMovementSpeed(1000.0f);
            SetEnemyVerticalMovementSpeed(200.f);
            SetEnemyDeathRadius(400.f);
            SetEnemyDeathScore(200);
        }

        PowerDuckController::~PowerDuckController() { }

        void PowerDuckController::Move()
        {
            MoveHorizontal(true);
            MoveVertical(true);
        }
    }
}
