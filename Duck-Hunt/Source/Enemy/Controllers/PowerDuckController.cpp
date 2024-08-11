#include "../../Header/Enemy/Controllers/PowerDuckController.h"

namespace Enemy
{
    namespace Controller
    {
        PowerDuckController::PowerDuckController(EnemyType type) : EnemyController(type) 
        { 
            horizontalMovementSpeed = 1000.0f;
            verticalMovementSpeed = 200.f;
            enemyDeathRadius = 400.f;
            enemyDeathScore = 200;
        }

        PowerDuckController::~PowerDuckController() { }

        void PowerDuckController::Move()
        {
            MoveHorizontal(true);
            MoveVertical(true);
        }
    }
}
