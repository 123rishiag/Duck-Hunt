#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
    enum class BulletType;

    class PlayerView;
    class PlayerModel;

    class PlayerController
    {
    private:
        PlayerView* playerView;
        PlayerModel* playerModel;

        void ProcessPlayerInput();
        void SetCurrentBullet();
        void OnShoot(sf::Vector2f position);

    public:
        PlayerController();
        ~PlayerController();

        void Initialize();
        void Update();
        void Render();

        void ReducePlayerHealth(int healthAmount);
        void IncreasePlayerScore(int score);
        void ReducePlayerPointAmmo();
        void ReducePlayerAreaAmmo();
        void ResetPlayerAmmo(int pointAmmoCount, int areaAmmoCount);

        int GetPlayerHealth() const;
        void ResetPlayerHealth();
        void ResetPlayerScore();
        int GetPlayerPointAmmo() const;
        int GetPlayerAreaAmmo() const;
        int GetPlayerScore() const;

        sf::Vector2f GetPlayerPosition() const;
        void SetPlayerPosition(sf::Vector2f position);

        float GetBulletRadius() const;
        void SetBulletRadius(float radius);
        BulletType GetCurrentBulletType() const;
        void SetCurrentBulletType(BulletType bulletType);
    };
}
