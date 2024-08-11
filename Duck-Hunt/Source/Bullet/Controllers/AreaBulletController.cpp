#include "../../Header/Bullet/Controllers/AreaBulletController.h"

namespace Bullet
{
	namespace Controller
	{
		AreaBulletController::AreaBulletController(BulletType type) : BulletController(type) 
		{ 
			SetProjectileRadius(150.f);
		}

		AreaBulletController::~AreaBulletController() { }
	}
}