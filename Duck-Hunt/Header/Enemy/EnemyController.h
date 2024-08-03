#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    enum class EnemyType;
    enum class EnemyState;

    class EnemyView;
    class EnemyModel;

    class EnemyController
    {
    protected:
        EnemyView* enemyView;
        EnemyModel* enemyModel;

        virtual void Move() = 0;

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        void Initialize();
        void Update();
        void Render();

        void Destroy();

        EnemyType GetEnemyType() const;
        EnemyState GetEnemyState() const;
        sf::Vector2f GetEnemyPosition();

        virtual float GetEnemyHorizontalMovementSpeed() = 0;
        virtual float GetEnemyVerticalMovementSpeed() = 0;
        virtual float GetEnemyDeathRadius() = 0;
    };
}