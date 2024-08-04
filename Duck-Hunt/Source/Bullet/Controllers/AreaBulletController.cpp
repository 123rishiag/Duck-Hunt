#include "../../Header/Bullet/Controllers/AreaBulletController.h"
#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	namespace Controller
	{
		AreaBulletController::AreaBulletController(BulletType type) : BulletController(type) { }

		AreaBulletController::~AreaBulletController() { }

		float AreaBulletController::GetBulletRadius()
		{
			return bulletRadius;
		}
	}
}