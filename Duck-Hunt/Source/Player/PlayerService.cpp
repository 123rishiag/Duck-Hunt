#include "../../Header/Player/PlayerService.h"
#include "../../Header/Player/PlayerController.h"

namespace Player
{
    PlayerService::PlayerService()
    {
        playerController = new PlayerController();
    }

    PlayerService::~PlayerService()
    {
        delete (playerController);
    }

    void PlayerService::Initialize(int initialHealth, int initialAmmo)
    {
        playerController->Initialize(initialHealth, initialAmmo);
    }

    void PlayerService::Update()
    {
        playerController->Update();
    }

    void PlayerService::Render()
    {
        playerController->Render();
    }

    PlayerController* PlayerService::GetPlayerController() const
    {
        return playerController;
    }
}
