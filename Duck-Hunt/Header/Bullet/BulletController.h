#pragma once
#include "../../Header/Projectile/IProjectile.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;

    class BulletController : public Projectile::IProjectile
    {
    protected:
        BulletView* bulletView;
        BulletModel* bulletModel;

    public:
        BulletController(BulletType type);
        virtual ~BulletController();

        void Initialize() override;
        void Update() override;
        void Render() override;
        void OnShoot(sf::Vector2f position) override;

        sf::Vector2f GetProjectilePosition() override;
        void SetProjectilePosition(sf::Vector2f position);

        BulletType GetProjectileType() override;
        void SetProjectileType(BulletType type);

        float GetProjectileRadius() override;
        void SetProjectileRadius(float radius);
    };
}