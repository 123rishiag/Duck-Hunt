#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class DuckController : public EnemyController
        {
        public:
            DuckController(EnemyType type);
            ~DuckController();
        };
    }
}