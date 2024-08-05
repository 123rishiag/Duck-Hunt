#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Bullet/BulletController.h"

namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Global;
        using namespace UI::UIElement;
        using namespace Player;
        using namespace Enemy;
        using namespace Bullet;

        GameplayUIController::GameplayUIController() { CreateUIElements(); }

        GameplayUIController::~GameplayUIController() { Destroy(); }

        void GameplayUIController::Initialize()
        {
            InitializeImage();
            InitializeText();
        }

        void GameplayUIController::CreateUIElements()
        {
            playerLivesImage = new ImageView();
            playerAmmoImage = new ImageView();
            enemyImage = new ImageView();
            scoreText = new TextView();
        }

        void GameplayUIController::InitializeImage()
        {
            playerLivesImage->Initialize(Config::playerHealthTexturePath, playerLivesSpriteWidth, playerLivesSpriteHeight, playerLivesPosition);
            playerAmmoImage->Initialize(BulletConfig::pointBulletTexturePath, playerAmmoSpriteWidth, playerAmmoSpriteHeight, playerAmmoPosition);
            enemyImage->Initialize(EnemyConfig::duckTexturePath, enemySpriteWidth, enemySpriteHeight, enemyPosition);
        }

        void GameplayUIController::InitializeText()
        {
            sf::String scoreString = "Score  :  0";
            scoreText->Initialize(scoreString, sf::Vector2f(scoreTextXPosition, scoreTextYPosition), FontType::BUBBLE_BOBBLE, fontSize, textColor);
        }

        void GameplayUIController::Update()
        {
            UpdateScoreText();
        }

        void GameplayUIController::Render()
        {
            scoreText->Render();
            DrawPlayerLives();
            DrawPlayerAmmo();
            DrawEnemy();
        }

        void GameplayUIController::Show()
        {
            playerLivesImage->Show();
            playerAmmoImage->Show();
            enemyImage->Show();
            scoreText->Show();
        }

        void GameplayUIController::UpdateScoreText()
        {
            int playerScore = ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerController()->GetPlayerScore();
            sf::String scoreString = "Score  :  " + std::to_string(playerScore);
            scoreText->SetText(scoreString);
        }

        void GameplayUIController::DrawPlayerLives()
        {
            int playerHealth = ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerController()->GetPlayerHealth();
            for (int counter = 0; counter < playerHealth; counter++)
            {
                playerLivesImage->SetPosition(sf::Vector2f(playerLivesPosition.x + playerLivesXOffset + (counter * playerLivesSpacing), playerLivesPosition.y + playerLivesYOffset));
                playerLivesImage->Render();
            }
        }

        void GameplayUIController::DrawPlayerAmmo()
        {
            int counter = 1;
            for (auto bullet : ServiceLocator::GetInstance()->GetBulletService()->GetAllBullets())
            {
                playerAmmoImage->SetPosition(sf::Vector2f(playerAmmoPosition.x + playerAmmoXOffset + (counter * playerAmmoSpacing), playerAmmoPosition.y + playerAmmoYOffset));
                playerAmmoImage->SetTexture(BulletConfig::GetBulletTexturePath(bullet->GetBulletType()));
                playerAmmoImage->Render();
                counter += 1;
            }
        }
        
        void GameplayUIController::DrawEnemy()
        {
            int counter = 1;
            for (auto enemy : ServiceLocator::GetInstance()->GetEnemyService()->GetAllEnemies())
            {
                enemyImage->SetPosition(sf::Vector2f(enemyPosition.x + enemyXOffset + (counter * enemySpacing), enemyPosition.y + enemyYOffset));
                enemyImage->SetTexture(EnemyConfig::GetEnemyTexturePath(enemy->GetEnemyType()));
                enemyImage->Render();
                counter += 1;
            }
        }

        void GameplayUIController::Destroy()
        {
            delete(playerLivesImage);
            delete(playerAmmoImage);
            delete(enemyImage);
            delete(scoreText);
        }
    }
}