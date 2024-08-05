#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class DuckController : public EnemyController
        {
        private:
            float horizontalMovementSpeed = 1000.0f;
            float verticalMovementSpeed = 200.f;
            float enemyDeathRadius = 100.f;
            int enemyDeathScore = 100;

        public:
            DuckController(EnemyType type);
            ~DuckController();

            float GetEnemyHorizontalMovementSpeed() override;
            float GetEnemyVerticalMovementSpeed() override;
            float GetEnemyDeathRadius() override;
            int GetEnemyDeathScore() override;
        };
    }
}