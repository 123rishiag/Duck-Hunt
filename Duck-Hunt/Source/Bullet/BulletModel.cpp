#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	BulletModel::BulletModel(BulletType type)
	{
		bulletType = type;
	}

	BulletModel::~BulletModel() { }

	void BulletModel::Initialize(float radius)
	{
		bulletRadius = radius;
	}

	sf::Vector2f BulletModel::GetBulletPosition()
	{
		return bulletPosition;
	}

	void BulletModel::SetBulletPosition(sf::Vector2f position)
	{
		bulletPosition = position;
	}

	BulletType BulletModel::GetBulletType() const
	{
		return bulletType;
	}

	void BulletModel::SetBulletType(BulletType type)
	{
		bulletType = type;
	}

	float BulletModel::GetBulletRadius() const
	{
		return bulletRadius;
	}

	void BulletModel::SetBulletRadius(float radius)
	{
		bulletRadius = radius;
	}
}