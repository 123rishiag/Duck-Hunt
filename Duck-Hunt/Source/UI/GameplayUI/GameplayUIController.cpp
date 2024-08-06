#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Utility/Utility.h"
#include <iomanip>
#include <sstream>

namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Global;
        using namespace UI::UIElement;
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
            waveTimeLeftText = new TextView();
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

            sf::String elapsedTimeString = "Time Left  :  0 secs";
            waveTimeLeftText->Initialize(elapsedTimeString, sf::Vector2f(waveTimeLeftTextXPosition, waveTimeLeftTextYPosition), FontType::BUBBLE_BOBBLE, fontSize, textColor);
        }

        void GameplayUIController::Update()
        {
            UpdateScoreText();
            UpdateWaveTimeLeftText();
        }

        void GameplayUIController::Render()
        {
            scoreText->Render();
            waveTimeLeftText->Render();

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
            waveTimeLeftText->Show();
        }

        void GameplayUIController::UpdateScoreText()
        {
            int playerScore = ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerScore();
            sf::String scoreString = "Score  :  " + std::to_string(playerScore);
            scoreText->SetText(scoreString);
        }

        void GameplayUIController::UpdateWaveTimeLeftText()
        {
            float timeLeft = ServiceLocator::GetInstance()->GetWaveService()->GetWaveTimeLeft();

            // Create a string stream and set the desired format
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(1) << timeLeft;

            // Convert the stream to a string
            std::string timeLeftStr = stream.str();

            // Convert the std::string to sf::String
            sf::String timeLeftString = "Time Left  :  " + sf::String(timeLeftStr) + " secs";

            // Set the text
            waveTimeLeftText->SetText(timeLeftString);
        }

        void GameplayUIController::DrawPlayerLives()
        {
            int playerHealth = ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerHealth();
            for (int counter = 0; counter < playerHealth; counter++)
            {
                playerLivesImage->SetPosition(sf::Vector2f(playerLivesPosition.x + playerLivesXOffset + (counter * playerLivesSpacing), playerLivesPosition.y + playerLivesYOffset));
                playerLivesImage->Render();
            }
        }

        void GameplayUIController::DrawPlayerAmmo()
        {

            int bulletTypeInt = static_cast<int>(ServiceLocator::GetInstance()->GetPlayerService()->GetCurrentBulletType());
            Bullet::BulletType playerBulletType = Utility::ToEnum<Bullet::BulletType>(bulletTypeInt);

            int ammoCounter = 0;
            
            for (int counter = 0; counter < ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerPointAmmo(); counter++)
            {
                playerAmmoImage->SetPosition(sf::Vector2f(playerAmmoPosition.x + playerAmmoXOffset + (counter * playerAmmoSpacing), playerAmmoPosition.y + playerAmmoYOffset));
                playerAmmoImage->SetTexture(BulletConfig::GetBulletTexturePath(Bullet::BulletType::POINT_BULLET));
                if (playerBulletType == Bullet::BulletType::POINT_BULLET)
                {
                    playerAmmoImage->SetScale(playerAmmoSpriteWidth * playerCurrentBulletScaleFactor, playerAmmoSpriteHeight * playerCurrentBulletScaleFactor);
                }
                else
                {
                    playerAmmoImage->SetScale(playerAmmoSpriteWidth, playerAmmoSpriteHeight);
                }
                playerAmmoImage->Render();
                ammoCounter += 1;
            }

            ammoCounter += 1;

            for (int counter = 0; counter < ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerAreaAmmo(); counter++)
            {
                playerAmmoImage->SetPosition(sf::Vector2f(playerAmmoPosition.x + playerAmmoXOffset + ((ammoCounter * playerCurrentBulletScaleFactor) * playerAmmoSpacing), playerAmmoPosition.y + playerAmmoYOffset));
                playerAmmoImage->SetTexture(BulletConfig::GetBulletTexturePath(Bullet::BulletType::AREA_BULLET));
                if (playerBulletType == Bullet::BulletType::AREA_BULLET)
                {
                    playerAmmoImage->SetScale(playerAmmoSpriteWidth * playerCurrentBulletScaleFactor, playerAmmoSpriteHeight * playerCurrentBulletScaleFactor);
                }
                else
                {
                    playerAmmoImage->SetScale(playerAmmoSpriteWidth, playerAmmoSpriteHeight);
                }
                playerAmmoImage->Render();
                ammoCounter += 1;
            }
        }
        
        void GameplayUIController::DrawEnemy()
        {
            int counter = 1;
            for (auto enemy : ServiceLocator::GetInstance()->GetEnemyService()->GetAllEnemies())
            {
                enemyImage->SetPosition(sf::Vector2f(enemyPosition.x + enemyXOffset + (counter * enemySpacing), enemyPosition.y + enemyYOffset));
                enemyImage->SetTexture(EnemyConfig::GetEnemyTexturePath(
                    ServiceLocator::GetInstance()->GetEnemyService()->GetEnemyType(enemy)
                ));
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
            delete(waveTimeLeftText);
        }
    }
}