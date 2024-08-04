#include "../../Header/Bullet/Controllers/PointBulletController.h"
#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	namespace Controller
	{
		PointBulletController::PointBulletController(BulletType type) : BulletController(type) { }

		PointBulletController::~PointBulletController() { }

		float PointBulletController::GetBulletRadius()
		{
			return bulletRadius;
		}
	}
}