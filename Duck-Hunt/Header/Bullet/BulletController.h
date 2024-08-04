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

        sf::Vector2f GetProjectilePosition() override;
        void OnShoot(sf::Vector2f position) override;
        virtual float GetBulletRadius() override = 0;
        BulletType GetBulletType() override;
    };
}