#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Utility/Utility.h"

namespace Player
{
    using namespace Global;
    using namespace Event;
    using namespace Projectile;
    using namespace Utility;

    PlayerController::PlayerController()
    {
        playerView = new PlayerView();
        playerModel = new PlayerModel();
    }

    PlayerController::~PlayerController()
    {
        delete (playerView);
        delete (playerModel);
    }

    void PlayerController::Initialize()
    {
        playerModel->Initialize();
        playerView->Initialize(this); // 'this' refers to the class we are currently inside
    }

    void PlayerController::Update()
    {
        ProcessPlayerInput();
        SetCurrentBullet();
        playerView->Update();
    }

    void PlayerController::Render()
    {
        playerView->Render(); // render the view
    }

    void PlayerController::ProcessPlayerInput()
    {
        EventService* eventService = ServiceLocator::GetInstance()->GetEventService();
        SetPlayerPosition(eventService->GetMousePosition());

        if (eventService->PressedLeftMouseButton())
        {
            OnShoot(GetPlayerPosition());
        }

        if(eventService->PressedRightMouseButton())
        {
            ServiceLocator::GetInstance()->GetBulletService()->ChangeBullets();;
        }
    }

    void PlayerController::SetCurrentBullet()
    {
        IProjectile* projectile = ServiceLocator::GetInstance()->GetBulletService()->GetCurrentBullet();
        if (projectile != nullptr)
        {
            int bulletTypeInt = static_cast<int>(projectile->GetBulletType());
            Player::BulletType playerBulletType = ToEnum<Player::BulletType>(bulletTypeInt);
            SetCurrentBulletType(playerBulletType);
            SetBulletRadius(projectile->GetBulletRadius());
        }
    }

    void PlayerController::OnShoot(sf::Vector2f position)
    {
        ServiceLocator::GetInstance()->GetBulletService()->OnShoot(position);
    }

    void PlayerController::ReducePlayerHealth(int healthAmount)
    {
        playerModel->ReducePlayerHealth(healthAmount);
    }

    void PlayerController::IncreasePlayerScore(int score)
    {
        playerModel->IncreasePlayerScore(score);
    }

    void PlayerController::ReducePlayerPointAmmo()
    {
        playerModel->ReducePlayerPointAmmo();
    }

    void PlayerController::ReducePlayerAreaAmmo()
    {
        playerModel->ReducePlayerAreaAmmo();
    }

    void PlayerController::ResetPlayerAmmo(int pointAmmoCount, int areaAmmoCount)
    {
        playerModel->ResetPlayerAmmo(pointAmmoCount, areaAmmoCount);
    }

    int PlayerController::GetPlayerHealth() const
    {
        return playerModel->GetPlayerHealth();
    }

    void PlayerController::ResetPlayerHealth()
    {
        playerModel->ResetPlayerHealth();
    }

    void PlayerController::ResetPlayerScore()
    {
        playerModel->ResetPlayerScore();
    }

    int PlayerController::GetPlayerPointAmmo() const
    {
        return playerModel->GetPlayerPointAmmo();
    }

    int PlayerController::GetPlayerAreaAmmo() const
    {
        return playerModel->GetPlayerAreaAmmo();
    }

    int PlayerController::GetPlayerScore() const
    {
        return playerModel->GetPlayerScore();
    }

    sf::Vector2f PlayerController::GetPlayerPosition() const
    {
        return playerModel->GetPlayerPosition();
    }

    void PlayerController::SetPlayerPosition(sf::Vector2f position)
    {
        return playerModel->SetPlayerPosition(position);
    }

    float PlayerController::GetBulletRadius() const
    {
        return playerModel->GetBulletRadius();
    }
    void PlayerController::SetBulletRadius(float radius)
    {
        playerModel->SetBulletRadius(radius);
    }

    BulletType PlayerController::GetCurrentBulletType() const
    {
        return playerModel->GetCurrentBulletType();
    }

    void PlayerController::SetCurrentBulletType(BulletType bulletType)
    {
        playerModel->SetCurrentBulletType(bulletType);
    }
}
