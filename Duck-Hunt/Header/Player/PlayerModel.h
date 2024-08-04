#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
    enum class BulletType;

    class PlayerModel
    {
    private:
        const int playerMaxHealth = 3;

        int playerHealth = 3;
        int playerAmmo = 10;
        int playerScore = 0;

        sf::Vector2f playerPosition;
        BulletType currentBulletType;
        float currentBulletRadius;

    public:
        PlayerModel();
        ~PlayerModel();

        void Initialize();
        void ReducePlayerHealth(int healthAmount);
        void IncreasePlayerScore(int score);
        void ReducePlayerAmmo();
        void ResetPlayerAmmo(int ammoCount);

        int GetPlayerHealth() const;
        int GetPlayerAmmo() const;
        int GetPlayerScore() const;

        sf::Vector2f GetPlayerPosition() const;
        void SetPlayerPosition(sf::Vector2f position);

        BulletType GetBulletType() const;
        void SetBulletType(BulletType type);

        float GetBulletRadius() const;
        void SetBulletRadius(float radius);
    };
}
