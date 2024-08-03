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

        void Initialize(int initialHealth, int initialAmmo);
        void Update();
        void Render();

        PlayerController* GetPlayerController() const;
    };
}
