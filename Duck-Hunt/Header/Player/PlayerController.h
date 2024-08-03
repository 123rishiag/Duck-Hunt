#pragma once

namespace Player
{
    class PlayerModel;

    class PlayerController
    {
    private:
        PlayerModel* playerModel;

    public:
        PlayerController();
        ~PlayerController();

        void Initialize(int initialHealth, int initialAmmo);
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
