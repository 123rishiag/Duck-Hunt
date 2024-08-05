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

    void PlayerService::Initialize()
    {
        playerController->Initialize();
    }

    void PlayerService::Update()
    {
        playerController->Update();
    }

    void PlayerService::Render()
    {
        playerController->Render();
    }

    void PlayerService::ReducePlayerHealth(int healthAmount)
    {
        playerController->ReducePlayerHealth(healthAmount);
    }

    void PlayerService::IncreasePlayerScore(int score)
    {
        playerController->IncreasePlayerScore(score);
    }

    void PlayerService::ReducePlayerAmmo()
    {
        playerController->ReducePlayerAmmo();
    }

    void PlayerService::ResetPlayerAmmo(int ammoCount)
    {
        playerController->ResetPlayerAmmo(ammoCount);
    }

    int PlayerService::GetPlayerHealth() const
    {
        return playerController->GetPlayerHealth();
    }

    int PlayerService::GetPlayerAmmo() const
    {
        return playerController->GetPlayerAmmo();
    }

    int PlayerService::GetPlayerScore() const
    {
        return playerController->GetPlayerScore();
    }

}
