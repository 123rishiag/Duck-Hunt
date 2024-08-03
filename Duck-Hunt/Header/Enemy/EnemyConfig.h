#pragma once

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
}