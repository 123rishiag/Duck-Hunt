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

    sf::Vector2f PlayerModel::GetPlayerPosition() const { return playerPosition; }
    void PlayerModel::SetPlayerPosition(sf::Vector2f position) { playerPosition = position; }

    BulletType PlayerModel::GetBulletType() const
    {
        return currentBulletType;
    }

    void PlayerModel::SetBulletType(BulletType type)
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
