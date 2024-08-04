#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../Header/Projectile/IProjectile.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;

	class BulletService
	{
	private:
		std::vector<Projectile::IProjectile*> flaggedBulletList;
		std::vector<Projectile::IProjectile*> bulletList;

		int bulletCount;
		int maxBullet = 300;

		void ProcessBulletSpawn();
		BulletType GetRandomBulletType() const;
		BulletController* CreateBullet(BulletType bulletType);

		bool IsValidBullet(int indexI, std::vector<Projectile::IProjectile*>& bulletList);
		void DestroyFlaggedBullets();

		void Destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void Initialize();
		void Update();
		void Render();

		BulletController* SpawnBullet();
		void OnShoot(sf::Vector2f position);
		Projectile::IProjectile* GetCurrentBullet();
		void DestroyBullet(BulletController* bulletController);

		void Reset();
	};
}