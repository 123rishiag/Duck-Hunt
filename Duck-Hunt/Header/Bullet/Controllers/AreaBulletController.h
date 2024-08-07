#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class AreaBulletController : public BulletController
        {
        private:
            const float bulletRadius = 150.f;

        public:
            AreaBulletController(BulletType type);
            ~AreaBulletController();

            float GetBulletRadius() override;
        };
    }
}