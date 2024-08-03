#pragma once

namespace Player
{
    class PlayerModel
    {
    private:
        int playerHealth = 3;
        int playerAmmo = 10;
        int playerScore = 0;

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
    };
}
