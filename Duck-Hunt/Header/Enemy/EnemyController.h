#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    enum class EnemyType;
    enum class EnemyState;

    enum class HorizontalMovementDirection;
    enum class VerticalMovementDirection;

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

        virtual void Move();
        void MoveHorizontal(bool isRandomVertical = false);
        void MoveVertical(bool isRandomHorizontal = false);

        float GetRandomOffset();
        float SmoothOffset(float currentOffset, float newOffset);
        HorizontalMovementDirection GetRandomEnemyHorizontalMovementDirection() const;
        VerticalMovementDirection GetRandomEnemyVerticalMovementDirection() const;

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        void Initialize();
        void Update();
        void Render();

        EnemyType GetEnemyType() const;
        EnemyState GetEnemyState() const;
        sf::Vector2f GetEnemyPosition();

        float GetEnemyHorizontalMovementSpeed() const;
        void SetEnemyHorizontalMovementSpeed(float speed);

        float GetEnemyVerticalMovementSpeed() const;
        void SetEnemyVerticalMovementSpeed(float speed);

        float GetEnemyDeathRadius() const;
        void SetEnemyDeathRadius(float radius);

        int GetEnemyDeathScore() const;
        void SetEnemyDeathScore(int score);

        void Destroy(bool increaseScore);
    };
}