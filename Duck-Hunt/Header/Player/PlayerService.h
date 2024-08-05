#pragma once

namespace Player
{
    class PlayerController;

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
        void ReducePlayerAmmo();
        void ResetPlayerAmmo(int ammoCount);

        int GetPlayerHealth() const;
        int GetPlayerAmmo() const;
        int GetPlayerScore() const;
    };
}
