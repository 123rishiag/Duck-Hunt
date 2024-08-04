#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
//#include "../../Header/Player/PlayerModel.h"

namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Global;
        //using namespace Player;
        using namespace UI::UIElement;

        GameplayUIController::GameplayUIController() { CreateUIElements(); }

        GameplayUIController::~GameplayUIController() { Destroy(); }

        void GameplayUIController::Initialize()
        {
            InitializeImage();
            InitializeText();
        }

        void GameplayUIController::CreateUIElements()
        {
            playerhealthCounterImage = new ImageView();
            scoreText = new TextView();
        }

        void GameplayUIController::InitializeImage()
        {
            playerhealthCounterImage->Initialize(Config::playerHealthTexturePath, playerhealthCounterSpriteWidth, playerhealthCounterSpriteHeight, sf::Vector2f(0, 0));
        }

        void GameplayUIController::InitializeText()
        {
            sf::String scoreString = "Score  :  0";
            scoreText->Initialize(scoreString, sf::Vector2f(scoreTextXPosition, textYPosition), FontType::BUBBLE_BOBBLE, fontSize, textColor);
        }

        void GameplayUIController::Update()
        {
            UpdateScoreText();
        }

        void GameplayUIController::Render()
        {
            scoreText->Render();
            DrawPlayerLives();
        }

        void GameplayUIController::Show()
        {
            playerhealthCounterImage->Show();
            scoreText->Show();
        }

        void GameplayUIController::UpdateScoreText()
        {
            sf::String scoreString = "Score  :  " + std::to_string(0);// PlayerModel::enemiesKilled);
            scoreText->SetText(scoreString);
        }

        void GameplayUIController::DrawPlayerLives()
        {
            sf::RenderWindow* game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

            for (int i = 0; i < 3; i++)
            {
                playerhealthCounterImage->SetPosition(sf::Vector2f(playerLivesXOffset + (i * playerLivesSpacing), playerLivesYOffset));
                playerhealthCounterImage->Render();
            }
        }

        void GameplayUIController::Destroy()
        {
            delete(playerhealthCounterImage);
            delete(scoreText);
        }
    }
}