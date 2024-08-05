#pragma once
#include <vector>
#include <unordered_map>
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

		int pointBulletCount;
		int areaBulletCount;

		void ProcessBulletSpawn();
		BulletController* CreateBullet(BulletType bulletType);

		void ReducePlayerAmmo(BulletType bulletType);

		bool IsValidBullet(int indexI, std::vector<Projectile::IProjectile*>& bulletList);
		void DestroyFlaggedBullets();

		void Destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void Initialize();
		void Update();
		void Render();

		BulletController* SpawnBullet(BulletType bulletType);
		void OnShoot(sf::Vector2f position);
		void ChangeBullets();
		Projectile::IProjectile* GetCurrentBullet();
		std::vector<Projectile::IProjectile*> GetAllBullets();
		void DestroyBullet(BulletController* bulletController);


		BulletType GetBulletType(Projectile::IProjectile* projectile) const;

		void Reset();
	};
}