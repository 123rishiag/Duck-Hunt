#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/Controllers/PointBulletController.h"
#include "../../Header/Global/ServiceLocator.h"
//#include "../../Header/Sound/SoundService.h"

namespace Bullet
{
	using namespace Projectile;
	using namespace Global;
	//using namespace Sound;

	BulletService::BulletService() { }

	BulletService::~BulletService() { Destroy(); }

	void BulletService::Initialize()
	{
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
			return new Controller::PointBulletController(Bullet::BulletType::POINT_BULLET);

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
		if (bulletCount < maxBullet)
		{
			SpawnBullet(); //spawn
		}
	}

	BulletController* BulletService::SpawnBullet()
	{
		BulletController* bulletController = CreateBullet(GetRandomBulletType());
		bulletController->Initialize();

		bulletList.push_back(bulletController);
		bulletCount += 1;
		return bulletController;
	}

	void BulletService::OnShoot(sf::Vector2f position)
	{
		if (!IsValidBullet(0, bulletList)) return;
		for (IProjectile* bullet : bulletList)
		{
			bullet->OnShoot(position);
			break;
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

	BulletType BulletService::GetRandomBulletType() const
	{
		int randomValue = std::rand() % (static_cast<int>(Bullet::BulletType::AREA_BULLET) + 1);
		return static_cast<Bullet::BulletType>(randomValue); //cast int to BulletType enum class
	}

	void BulletService::DestroyBullet(BulletController* bulletController)
	{
		if (std::find(flaggedBulletList.begin(), flaggedBulletList.end(), bulletController) == flaggedBulletList.end())
		{
			flaggedBulletList.push_back(bulletController);
			bulletList.erase(std::remove(bulletList.begin(), bulletList.end(), bulletController), bulletList.end());
		}
	}

	void BulletService::Reset() { Destroy(); }
}