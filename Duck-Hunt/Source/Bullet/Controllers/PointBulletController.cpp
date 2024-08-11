#include "../../Header/Bullet/Controllers/PointBulletController.h"

namespace Bullet
{
	namespace Controller
	{
		PointBulletController::PointBulletController(BulletType type) : BulletController(type) 
		{ 
			SetProjectileRadius(50.f);
		}

		PointBulletController::~PointBulletController() { }
	}
}