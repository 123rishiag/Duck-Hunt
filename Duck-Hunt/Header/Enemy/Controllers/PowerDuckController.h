#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class PowerDuckController : public EnemyController
        {
        private:
            void Move() override;

        public:
            PowerDuckController(EnemyType type);
            ~PowerDuckController();
        };
    }
}