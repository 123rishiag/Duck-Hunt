#include "../../Header/Player/PlayerModel.h"

namespace Player
{
    PlayerModel::PlayerModel() {}

    PlayerModel::~PlayerModel() {}

    void PlayerModel::Initialize()
    {
    }

    void PlayerModel::ReducePlayerHealth(int healthAmount)
    {
        playerHealth -= healthAmount;
    }

    void PlayerModel::IncreasePlayerScore(int score)
    {
        playerScore += score;
    }

    void PlayerModel::ReducePlayerAmmo()
    {
        if (playerAmmo > 0)
        {
            playerAmmo -= 1;
        }
    }

    void PlayerModel::ResetPlayerAmmo(int ammoCount)
    {
        playerAmmo = ammoCount;
    }

    int PlayerModel::GetPlayerHealth() const
    {
        return playerHealth;
    }

    int PlayerModel::GetPlayerAmmo() const
    {
        return playerAmmo;
    }

    int PlayerModel::GetPlayerScore() const
    {
        return playerScore;
    }
}
