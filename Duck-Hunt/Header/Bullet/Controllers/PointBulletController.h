#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class PointBulletController : public BulletController
        {
        public:
            PointBulletController(BulletType type);
            ~PointBulletController();
        };
    }
}