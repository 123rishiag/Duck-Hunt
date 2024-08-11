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
        int playerPointAmmo = 3;
        int playerAreaAmmo = 1;
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
        void ReducePlayerPointAmmo();
        void ReducePlayerAreaAmmo();

        int GetPlayerHealth() const;
        int GetPlayerPointAmmo() const;
        int GetPlayerAreaAmmo() const;
        int GetPlayerScore() const;

        sf::Vector2f GetPlayerPosition() const;
        void SetPlayerPosition(sf::Vector2f position);

        BulletType GetCurrentBulletType() const;
        void SetCurrentBulletType(BulletType type);

        float GetBulletRadius() const;
        void SetBulletRadius(float radius);

        void ResetPlayerAmmo(int pointAmmoCount, int areaAmmoCount);
        void ResetPlayerHealth();
        void ResetPlayerScore();
    };
}
