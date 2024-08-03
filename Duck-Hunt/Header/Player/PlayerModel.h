#pragma once

namespace Player
{
    class PlayerModel
    {
    private:
        int playerHealth;
        int playerAmmo;
        int playerScore;

    public:
        PlayerModel();
        ~PlayerModel();

        void Initialize(int initialHealth, int initialAmmo);
        void ReducePlayerHealth(int healthAmount);
        void IncreasePlayerScore(int score);
        void ReducePlayerAmmo();
        void ResetPlayerAmmo(int ammoCount);

        int GetPlayerHealth() const;
        int GetPlayerAmmo() const;
        int GetPlayerScore() const;
    };
}
