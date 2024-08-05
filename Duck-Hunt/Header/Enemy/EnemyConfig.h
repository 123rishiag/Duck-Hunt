#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    enum class EnemyType
    {
        DUCK,
        POWER_DUCK,
    };

    enum class EnemyState
    {
        ALIVE,
        DEAD,
    };

    enum class HorizontalMovementDirection
    {
        LEFT,
        RIGHT,
    };

    enum class VerticalMovementDirection
    {
        UP,
        DOWN,
    };

    class EnemyConfig
    {
    public:
        static const sf::String duckTexturePath;
        static const sf::String powerDuckTexturePath;
        static const sf::String GetEnemyTexturePath(EnemyType enemyType);
    };
}