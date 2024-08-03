#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
    enum class BulletType;

    class BulletModel
    {
    private:
        BulletType bulletType;
        sf::Vector2f bulletPosition;
        float bulletRadius;

    public:

        BulletModel(BulletType type);
        ~BulletModel();

        void Initialize(float radius);

        sf::Vector2f GetBulletPosition();
        void SetBulletPosition(sf::Vector2f position);

        BulletType GetBulletType() const;
        void SetBulletType(BulletType type);

        float GetBulletRadius() const;
        void SetBulletRadius(float radius);

    };
}