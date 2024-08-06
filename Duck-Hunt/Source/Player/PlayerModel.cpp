#include "../../Header/Player/PlayerModel.h"

namespace Player
{
    PlayerModel::PlayerModel() { }

    PlayerModel::~PlayerModel() { }

    void PlayerModel::Initialize()
    {
        playerHealth = playerMaxHealth;
    }

    void PlayerModel::ReducePlayerHealth(int healthAmount)
    {
        playerHealth -= healthAmount;
    }

    void PlayerModel::IncreasePlayerScore(int score)
    {
        playerScore += score;
    }

    void PlayerModel::ReducePlayerPointAmmo()
    {
        if (playerPointAmmo > 0)
        {
            playerPointAmmo -= 1;
        }
    }

    void PlayerModel::ReducePlayerAreaAmmo()
    {
        if (playerAreaAmmo > 0)
        {
            playerAreaAmmo -= 1;
        }
    }

    void PlayerModel::ResetPlayerAmmo(int pointAmmoCount, int areaAmmoCount)
    {
        playerPointAmmo = pointAmmoCount;
        playerAreaAmmo = areaAmmoCount;
    }

    int PlayerModel::GetPlayerHealth() const
    {
        return playerHealth;
    }

    void PlayerModel::ResetPlayerHealth()
    {
        playerHealth = playerMaxHealth;
    }

    int PlayerModel::GetPlayerPointAmmo() const
    {
        return playerPointAmmo;
    }

    int PlayerModel::GetPlayerAreaAmmo() const
    {
        return playerAreaAmmo;
    }

    int PlayerModel::GetPlayerScore() const
    {
        return playerScore;
    }

    sf::Vector2f PlayerModel::GetPlayerPosition() const { return playerPosition; }
    void PlayerModel::SetPlayerPosition(sf::Vector2f position) { playerPosition = position; }

    BulletType PlayerModel::GetCurrentBulletType() const
    {
        return currentBulletType;
    }

    void PlayerModel::SetCurrentBulletType(BulletType type)
    {
        currentBulletType = type;
    }

    float PlayerModel::GetBulletRadius() const
    {
        return currentBulletRadius;
    }

    void PlayerModel::SetBulletRadius(float radius)
    {
        currentBulletRadius = radius;
    }
}
