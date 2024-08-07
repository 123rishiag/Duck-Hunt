#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class DuckController : public EnemyController
        {
        private:
            float horizontalMovementSpeed = 750.0f;
            float verticalMovementSpeed = 150.f;
            float enemyDeathRadius = 100.f;
            int enemyDeathScore = 100;

            void Move() override;
            void MoveHorizontal();
            void MoveVertical();

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