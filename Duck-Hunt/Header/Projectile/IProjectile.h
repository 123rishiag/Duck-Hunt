#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../Header/Bullet/BulletConfig.h"

namespace Projectile
{
	class IProjectile
	{
	public:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		virtual void OnShoot(sf::Vector2f position) = 0;

		virtual sf::Vector2f GetProjectilePosition() = 0;
		virtual Bullet::BulletType GetProjectileType() = 0;
		virtual float GetProjectileRadius() = 0;

		virtual ~IProjectile() {};
	};
}
