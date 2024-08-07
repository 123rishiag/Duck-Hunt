#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletModel.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Sound/SoundService.h"

namespace Bullet
{
    using namespace Global;
    using namespace Player;
    using namespace Enemy;
    using namespace Sound;

    BulletController::BulletController(BulletType type)
    {
        bulletModel = new BulletModel(type);
    }
    BulletController::~BulletController()
    {
        delete (bulletView);
        delete (bulletModel);
    }
    void BulletController::Initialize()
    {
        bulletModel->Initialize(GetBulletRadius());
    }
    void BulletController::Update()
    {
    }
    void BulletController::Render()
    {
    }

    void BulletController::OnShoot(sf::Vector2f position)
    {
        bulletModel->SetBulletPosition(position);
        ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemyByPosition(GetProjectilePosition(),GetBulletRadius());
        ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BULLET_FIRE);
        ServiceLocator::GetInstance()->GetBulletService()->DestroyBullet(this);
    }

    sf::Vector2f BulletController::GetProjectilePosition()
    {
        return bulletModel->GetBulletPosition();
    }

    BulletType BulletController::GetBulletType()
    {
        return bulletModel->GetBulletType();
    }

}