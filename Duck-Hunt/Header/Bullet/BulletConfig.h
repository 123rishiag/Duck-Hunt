#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
	enum class BulletType
	{
		POINT_BULLET,
		AREA_BULLET,
	};

	class BulletConfig
	{
	public:
		static const sf::String pointBulletTexturePath;
		static const sf::String areaBulletTexturePath;
		static const sf::String GetBulletTexturePath(BulletType bulletType);
	};
}