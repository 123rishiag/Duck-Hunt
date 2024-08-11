#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/Controllers/PointBulletController.h"
#include "../../Header/Bullet/Controllers/AreaBulletController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Projectile;
	using namespace Global;

	BulletService::BulletService() { }

	BulletService::~BulletService() { Destroy(); }

	void BulletService::Initialize()
	{
		pointBulletCount = 0;
		areaBulletCount = 0;
	}

	void BulletService::Update()
	{
		ProcessBulletSpawn();
		for (IProjectile* bullet : bulletList)
			bullet->Update();
		DestroyFlaggedBullets();
	}

	void BulletService::Render()
	{
		for (IProjectile * bullet : bulletList)
			bullet->Render();
	}

	BulletController* BulletService::CreateBullet(BulletType bulletType)
	{
		switch (bulletType)
		{
		case::Bullet::BulletType::POINT_BULLET:
			return new Controller::PointBulletController(Bullet::BulletType::POINT_BULLET);
		case::Bullet::BulletType::AREA_BULLET:
			return new Controller::AreaBulletController(Bullet::BulletType::AREA_BULLET);
		default:
			return nullptr;
		}
	}

	bool BulletService::IsValidBullet(int index, std::vector<Projectile::IProjectile*>& bulletList)
	{
		return index >= 0 && index < bulletList.size() && bulletList[index] != nullptr;
	}

	void BulletService::DestroyFlaggedBullets()
	{
		for (int i = 0; i < flaggedBulletList.size(); i++)
		{
			if (!IsValidBullet(i, flaggedBulletList)) continue;

			delete (flaggedBulletList[i]);
		}
		flaggedBulletList.clear();
	}

	void BulletService::Destroy()
	{
		for (int i = 0; i < bulletList.size(); i++)
		{
			if (!IsValidBullet(i, bulletList)) continue;
		}
		bulletList.clear();
	}

	void BulletService::ProcessBulletSpawn()
	{
		while(pointBulletCount < ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerPointAmmo())
		{
			SpawnBullet(Bullet::BulletType::POINT_BULLET); //spawn
			pointBulletCount += 1;
		}

		while (areaBulletCount < ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerAreaAmmo())
		{
			SpawnBullet(Bullet::BulletType::AREA_BULLET); //spawn
			areaBulletCount += 1;
		}
	}

	BulletController* BulletService::SpawnBullet(BulletType bulletType)
	{
		BulletController* bulletController = CreateBullet(bulletType);
		bulletController->Initialize();

		bulletList.push_back(bulletController);
		return bulletController;
	}

	void BulletService::ReducePlayerAmmo(BulletType bulletType)
	{
		switch (bulletType)
		{
		case::Bullet::BulletType::POINT_BULLET:
			ServiceLocator::GetInstance()->GetPlayerService()->ReducePlayerPointAmmo();
			break;
		case::Bullet::BulletType::AREA_BULLET:
			ServiceLocator::GetInstance()->GetPlayerService()->ReducePlayerAreaAmmo();
			break;
		}
	}

	void BulletService::OnShoot(sf::Vector2f position)
	{
		if (!IsValidBullet(0, bulletList)) return;
		IProjectile* bullet = GetCurrentBullet();
		bullet->OnShoot(position);
		ReducePlayerAmmo(bullet->GetProjectileType());
	}

	void BulletService::ChangeBullets()
	{
		if (!IsValidBullet(0, bulletList)) return;

		// Map to store the bullet type and their corresponding bullets
		std::unordered_map<BulletType, std::vector<Projectile::IProjectile*>> bulletMap;

		// Categorize bullets based on their type
		for (Projectile::IProjectile* bullet : bulletList)
		{
			bulletMap[bullet->GetProjectileType()].push_back(bullet);
		}

		// Vector to store the bullet types in the order they were found
		std::vector<BulletType> bulletTypes;
		for (const auto& pair : bulletMap)
		{
			bulletTypes.push_back(pair.first);
		}

		// Rotate the bullet types to the left
		std::rotate(bulletTypes.begin(), bulletTypes.begin() + 1, bulletTypes.end());

		// Clear the original list and reorder based on the rotated bullet types
		bulletList.clear();
		for (const auto& type : bulletTypes)
		{
			bulletList.insert(bulletList.end(), bulletMap[type].begin(), bulletMap[type].end());
		}
	}

	Projectile::IProjectile* BulletService::GetCurrentBullet()
	{
		if (IsValidBullet(0, bulletList))
		{
			return bulletList[0];
		}
		return nullptr;
	}

	std::vector<Projectile::IProjectile*> BulletService::GetAllBullets()
	{
		return bulletList;
	}

	void BulletService::DestroyBullet(BulletController* bulletController)
	{
		if (std::find(flaggedBulletList.begin(), flaggedBulletList.end(), bulletController) == flaggedBulletList.end())
		{
			flaggedBulletList.push_back(bulletController);
			bulletList.erase(std::remove(bulletList.begin(), bulletList.end(), bulletController), bulletList.end());
		}
	}

	BulletType BulletService::GetBulletType(Projectile::IProjectile* projectile) const
	{
		return projectile->GetProjectileType();
	}

	void BulletService::Reset() 
	{ 
		pointBulletCount = 0;
		areaBulletCount = 0;
		Destroy();
	}
}