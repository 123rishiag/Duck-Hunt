#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    enum class EnemyType;

    enum class HorizontalMovementDirection;
    enum class VerticalMovementDirection;

    enum class EnemyState;

    class EnemyModel
    {
    private:
        sf::Vector2f referencePosition = sf::Vector2f(900.f, 900.f);
        sf::Vector2f enemyPosition;

        HorizontalMovementDirection horizontalMovementDirection;
        VerticalMovementDirection verticalMovementDirection;
        EnemyType enemyType;
        EnemyState enemyState;

        float horizontalMovementSpeed;
        float verticalMovementSpeed;
        float enemyDeathRadius;

    public:
        EnemyModel(EnemyType type);
        ~EnemyModel();

        //const data related to movement and bounds
        const float leftMostPosition = 50.f;
        const float rightMostPosition = 1800.f;
        const float upMostPosition = 50.f;
        const float downMostPosition = 900.f;

        void Initialize(float hSpeed,float ySpeed, 
            HorizontalMovementDirection hMoveDirection, VerticalMovementDirection vMoveDirection, 
            float radius);

        sf::Vector2f GetReferencePosition() const;
        void SetReferencePosition(sf::Vector2f position);

        sf::Vector2f GetEnemyPosition() const;
        void SetEnemyPosition(sf::Vector2f position);

        EnemyType GetEnemyType() const;
        void SetEnemyType(EnemyType type);

        EnemyState GetEnemyState() const;
        void SetEnemyState(EnemyState state);

        HorizontalMovementDirection GetHorizontalMovementDirection() const;
        void SetHorizontalMovementDirection(HorizontalMovementDirection direction);

        VerticalMovementDirection GetVerticalMovementDirection() const;
        void SetVerticalMovementDirection(VerticalMovementDirection direction);

        float GetHorizontalMovementSpeed() const;
        void SetHorizontalMovementSpeed(float speed);

        float GetVerticalMovementSpeed() const;
        void SetVerticalMovementSpeed(float speed);

        float GetEnemyDeathRadius() const;
        void SetEnemyDeathRadius(float radius);

        int GetEnemyDeathScore() const;
        void SetEnemyDeathScore(int score);

    };
}