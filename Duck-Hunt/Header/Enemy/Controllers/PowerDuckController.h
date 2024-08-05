#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class PowerDuckController : public EnemyController
        {
        private:
            float horizontalMovementSpeed = 1500.0f;
            float verticalMovementSpeed = 300.f;
            float enemyDeathRadius = 600.f;
            int enemyDeathScore = 200;

            void Move() override;
            void MoveHorizontal();
            void MoveVertical();


        public:
            PowerDuckController(EnemyType type);
            ~PowerDuckController();

            float GetEnemyHorizontalMovementSpeed() override;
            float GetEnemyVerticalMovementSpeed() override;
            float GetEnemyDeathRadius() override;
            int GetEnemyDeathScore() override;
        };
    }
}