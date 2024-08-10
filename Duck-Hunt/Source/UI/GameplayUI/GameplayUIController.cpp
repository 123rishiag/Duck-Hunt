#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Bullet/BulletConfig.h"
#include"../../Header/Utility/Utility.h"
#include "../../Header/Wave/WaveConfig.h"
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
        using namespace Wave;

        GameplayUIController::GameplayUIController() { CreateUIElements(); }

        GameplayUIController::~GameplayUIController() { Destroy(); }

        void GameplayUIController::Initialize()
        {
            InitializeImage();
            InitializeText();
        }

        void GameplayUIController::CreateUIElements()
        {
            images.push_back(new ImageView()); // playerLivesImage
            images.push_back(new ImageView()); // playerAmmoImage
            images.push_back(new ImageView()); // enemyImage

            texts.push_back(new TextView()); // scoreText
            texts.push_back(new TextView()); // waveTimeLeftText
            texts.push_back(new TextView()); // waveNameText
            texts.push_back(new TextView()); // waveInfoText
        }

        void GameplayUIController::InitializeImage()
        {
            images[0]->Initialize(Config::playerHealthTexturePath, playerLivesSpriteWidth, playerLivesSpriteHeight, playerLivesPosition);
            images[1]->Initialize(BulletConfig::pointBulletTexturePath, playerAmmoSpriteWidth, playerAmmoSpriteHeight, playerAmmoPosition);
            images[2]->Initialize(EnemyConfig::duckTexturePath, enemySpriteWidth, enemySpriteHeight, enemyPosition);
        }

        void GameplayUIController::InitializeText()
        {
            sf::String scoreString = "Score  :  0";
            texts[0]->Initialize(scoreString, sf::Vector2f(scoreTextXPosition, scoreTextYPosition), FontType::BUBBLE_BOBBLE, fontSize, textColor);

            sf::String elapsedTimeString = "Time Left  :  0 secs";
            texts[1]->Initialize(elapsedTimeString, sf::Vector2f(waveTimeLeftTextXPosition, waveTimeLeftTextYPosition), FontType::BUBBLE_BOBBLE, fontSize, textColor);

            sf::String waveNameString = "Wave Number";
            texts[2]->Initialize(waveNameString, sf::Vector2f(waveNameTextXPosition, waveNameTextYPosition), FontType::BUBBLE_BOBBLE, fontSize, textColor);

            sf::String waveStateString = "Wave Information";
            texts[3]->Initialize(waveStateString, sf::Vector2f(waveInfoTextXPosition, waveInfoTextYPosition), FontType::BUBBLE_BOBBLE, fontSize * 2, textColor);
        }

        void GameplayUIController::Update()
        {
            UpdateScoreText();
            UpdateWaveTimeLeftText();
            UpdateWaveNameText();
            UpdateWaveInfoText();
        }

        void GameplayUIController::Render()
        {

            DrawPlayerLives();
            DrawPlayerAmmo();
            DrawEnemy();

            for (auto& text : texts)
            {
                text->Render();
            }
        }

        void GameplayUIController::Show()
        {
            for (auto& image : images)
            {
                image->Show();
            }

            for (auto& text : texts)
            {
                text->Show();
            }
        }

        void GameplayUIController::UpdateScoreText()
        {
            int playerScore = ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerScore();
            sf::String scoreString = "Score  :  " + std::to_string(playerScore);
            texts[0]->SetText(scoreString);
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
            texts[1]->SetText(timeLeftString);
        }

        void GameplayUIController::UpdateWaveNameText()
        {
            Wave::WaveState waveState = ServiceLocator::GetInstance()->GetWaveService()->GetWaveState();
            if (waveState == Wave::WaveState::WAVE_BOOT)
            {
                waveNameString = ServiceLocator::GetInstance()->GetWaveService()->GetWaveName();
            }
            texts[2]->SetText(waveNameString);
        }

        void GameplayUIController::UpdateWaveInfoText()
        {
            Wave::WaveState waveState = ServiceLocator::GetInstance()->GetWaveService()->GetWaveState();
            Wave::WaveResult waveResult = ServiceLocator::GetInstance()->GetWaveService()->GetWaveResult();
            bool isGameOver = ServiceLocator::GetInstance()->GetWaveService()->IsGameOver();
            sf::String waveInfoString = "";

            switch (waveState)
            {
            case::Wave::WaveState::WAVE_BOOT:
                    waveInfoString = "Wave Start";
                    break;
            case::Wave::WaveState::WAVE_RESULT:
                switch (waveResult) 
                {
                case Wave::WaveResult::WAVE_WON:
                    waveInfoString = "Wave Won";
                    if (isGameOver)
                    {
                        waveInfoString = "Game Won";
                    }
                    break;
                case Wave::WaveResult::WAVE_LOST:
                    waveInfoString = "Wave Lost";
                    if (isGameOver)
                    {
                        waveInfoString = "Game Over";
                    }
                    ServiceLocator::GetInstance()->GetGameplayService()->ActivateBackgroundAlpha(true);
                    break;
                default:
                    waveInfoString = "";
                    break;
                }
                break;
            default:
                waveInfoString = "";
                break;
            }
            texts[3]->SetText(waveInfoString);
        }

        void GameplayUIController::DrawPlayerLives()
        {
            int playerHealth = ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerHealth();
            for (int counter = 0; counter < playerHealth; counter++)
            {
                images[0]->SetPosition(sf::Vector2f(playerLivesPosition.x + playerLivesXOffset + (counter * playerLivesSpacing), playerLivesPosition.y + playerLivesYOffset));
                images[0]->Render();
            }
        }

        void GameplayUIController::DrawPlayerAmmo()
        {
            auto playerService = ServiceLocator::GetInstance()->GetPlayerService();

            struct AmmoData
            {
                int ammoCount;
                Bullet::BulletType bulletType;
            };

            std::vector<AmmoData> ammoDataList = {
                { playerService->GetPlayerPointAmmo(), Bullet::BulletType::POINT_BULLET },
                { playerService->GetPlayerAreaAmmo(), Bullet::BulletType::AREA_BULLET }
            };

            int ammoCounter = 0;

            for (const auto& ammoData : ammoDataList)
            {
                for (int counter = 0; counter < ammoData.ammoCount; counter++)
                {
                    images[1]->SetPosition(sf::Vector2f(
                        playerAmmoPosition.x + playerAmmoXOffset + (ammoCounter * playerAmmoSpacing),
                        playerAmmoPosition.y + playerAmmoYOffset
                    ));

                    images[1]->SetTexture(BulletConfig::GetBulletTexturePath(ammoData.bulletType));

                    if (static_cast<int>(playerService->GetCurrentBulletType()) == static_cast<int>(ammoData.bulletType))
                    {
                        images[1]->SetScale(playerAmmoSpriteWidth * playerCurrentBulletScaleFactor, playerAmmoSpriteHeight * playerCurrentBulletScaleFactor);
                    }
                    else
                    {
                        images[1]->SetScale(playerAmmoSpriteWidth, playerAmmoSpriteHeight);
                    }

                    images[1]->Render();
                    ammoCounter += 1;
                }
                // To add spacing between different ammo types, adjust the counter if necessary.
                ammoCounter += 2;
            }
        }
        
        void GameplayUIController::DrawEnemy()
        {
            int counter = 1;
            for (auto enemy : ServiceLocator::GetInstance()->GetEnemyService()->GetAllEnemies())
            {
                images[2]->SetPosition(sf::Vector2f(enemyPosition.x + enemyXOffset + (counter * enemySpacing), enemyPosition.y + enemyYOffset));
                images[2]->SetTexture(EnemyConfig::GetEnemyTexturePath(
                    ServiceLocator::GetInstance()->GetEnemyService()->GetEnemyType(enemy)
                ));
                images[2]->Render();
                counter += 1;
            }
        }

        void GameplayUIController::Destroy()
        {
            for (auto& image : images)
            {
                delete image;
            }
            images.clear();

            for (auto& text : texts)
            {
                delete text;
            }
            texts.clear();
        }
    }
}