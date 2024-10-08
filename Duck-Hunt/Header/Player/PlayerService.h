#pragma once
#include"../../Header/Bullet/BulletConfig.h"

namespace Player
{
    class PlayerController;
    enum class BulletType;

    class PlayerService
    {
    private:
        PlayerController* playerController;

    public:
        PlayerService();
        ~PlayerService();

        void Initialize();
        void Update();
        void Render();

        void ReducePlayerHealth(int healthAmount);
        void IncreasePlayerScore(int score);
        void ReducePlayerPointAmmo();
        void ReducePlayerAreaAmmo();
        void ResetPlayerAmmo(int pointAmmoCount, int areaAmmoCount);

        bool IsPlayerAlive() const;

        int GetPlayerHealth() const;
        int GetPlayerPointAmmo() const;
        int GetPlayerAreaAmmo() const;
        int GetPlayerScore() const;
        BulletType GetCurrentBulletType();

        void ResetPlayerHealth();
        void ResetPlayerScore();

        void Reset(int pointAmmoCount, int areaAmmoCount);
    };
}
