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

        float horizontalOffset;
        float verticalOffset;
        float previousHorizontalOffset = 0.0f;
        float previousVerticalOffset = 0.0f;
        float smoothingFactor = 0.00001f;

        virtual void Move() = 0;

        float GetRandomOffset();
        float SmoothOffset(float currentOffset, float newOffset);

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        void Initialize();
        void Update();
        void Render();

        void Destroy(bool increaseScore);

        EnemyType GetEnemyType() const;
        EnemyState GetEnemyState() const;
        sf::Vector2f GetEnemyPosition();

        virtual float GetEnemyHorizontalMovementSpeed() = 0;
        virtual float GetEnemyVerticalMovementSpeed() = 0;
        virtual float GetEnemyDeathRadius() = 0;
        virtual int GetEnemyDeathScore() = 0;
    };
}