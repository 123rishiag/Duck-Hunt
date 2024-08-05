#include"../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
	const sf::String BulletConfig::pointBulletTexturePath = "assets/textures/point_bullet.png";
	const sf::String BulletConfig::areaBulletTexturePath = "assets/textures/area_bullet.png";

	const sf::String BulletConfig::GetBulletTexturePath(BulletType bulletType)
	{
		switch (bulletType)
		{
		case::Bullet::BulletType::POINT_BULLET:
			return BulletConfig::pointBulletTexturePath;
		case::Bullet::BulletType::AREA_BULLET:
			return BulletConfig::areaBulletTexturePath;
		}
	}
}