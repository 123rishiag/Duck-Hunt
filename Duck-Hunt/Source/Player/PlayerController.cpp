#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"

namespace Player
{
    PlayerController::PlayerController()
    {
        playerModel = new PlayerModel();
    }

    PlayerController::~PlayerController()
    {
        delete playerModel;
    }

    void PlayerController::Initialize(int initialHealth, int initialAmmo)
    {
        playerModel->Initialize(initialHealth, initialAmmo);
    }

    void PlayerController::Update()
    {
        // Update player state if necessary
    }

    void PlayerController::Render()
    {
        // Render player UI elements if necessary
    }

    void PlayerController::ReducePlayerHealth(int healthAmount)
    {
        playerModel->ReducePlayerHealth(healthAmount);
    }

    void PlayerController::IncreasePlayerScore(int score)
    {
        playerModel->IncreasePlayerScore(score);
    }

    void PlayerController::ReducePlayerAmmo()
    {
        playerModel->ReducePlayerAmmo();
    }

    void PlayerController::ResetPlayerAmmo(int ammoCount)
    {
        playerModel->ResetPlayerAmmo(ammoCount);
    }
    
    int PlayerController::GetPlayerHealth() const
    {
        return playerModel->GetPlayerHealth();
    }

    int PlayerController::GetPlayerAmmo() const
    {
        return playerModel->GetPlayerAmmo();
    }

    int PlayerController::GetPlayerScore() const
    {
        return playerModel->GetPlayerScore();
    }
}
