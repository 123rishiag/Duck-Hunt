#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class PointBulletController : public BulletController
        {
        private:
            const float bulletRadius = 100.f;

        public:
            PointBulletController(BulletType type);
            ~PointBulletController();

            float GetBulletRadius() override;
        };
    }
}