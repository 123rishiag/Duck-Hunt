#pragma once
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;

    enum class BulletType;

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
        virtual float GetBulletRadius() = 0;
        BulletType GetBulletType() const;
    };
}