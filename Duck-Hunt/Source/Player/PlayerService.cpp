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

    void PlayerService::ReducePlayerPointAmmo()
    {
        playerController->ReducePlayerPointAmmo();
    }

    void PlayerService::ReducePlayerAreaAmmo()
    {
        playerController->ReducePlayerAreaAmmo();
    }

    void PlayerService::ResetPlayerAmmo(int pointAmmoCount, int areaAmmoCount)
    {
        playerController->ResetPlayerAmmo(pointAmmoCount, areaAmmoCount);
    }

    bool PlayerService::IsPlayerAlive() const
    {
        return playerController->GetPlayerHealth() > 0 ? true : false;
    }

    int PlayerService::GetPlayerHealth() const
    {
        return playerController->GetPlayerHealth();
    }

    int PlayerService::GetPlayerPointAmmo() const
    {
        return playerController->GetPlayerPointAmmo();
    }

    int PlayerService::GetPlayerAreaAmmo() const
    {
        return playerController->GetPlayerAreaAmmo();
    }

    int PlayerService::GetPlayerScore() const
    {
        return playerController->GetPlayerScore();
    }

    BulletType PlayerService::GetCurrentBulletType()
    {
        return playerController->GetCurrentBulletType();
    }

    void PlayerService::ResetPlayerHealth()
    {
        playerController->ResetPlayerHealth();
    }

    void PlayerService::ResetPlayerScore()
    {
        playerController->ResetPlayerScore();
    }

    void PlayerService::Reset(int pointAmmoCount, int areaAmmoCount)
    {
        ResetPlayerAmmo(pointAmmoCount, areaAmmoCount);
    }
}
