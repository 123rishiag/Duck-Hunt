#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class AreaBulletController : public BulletController
        {
        public:
            AreaBulletController(BulletType type);
            ~AreaBulletController();
        };
    }
}