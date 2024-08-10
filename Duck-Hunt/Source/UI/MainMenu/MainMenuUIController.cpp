#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Sound/SoundService.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Sound;

        MainMenuUIController::MainMenuUIController()
        {
            CreateImages();
            CreateButtons();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            Destroy();
        }

        void MainMenuUIController::Initialize()
        {
            InitializeImages();
            InitializeButtons();
            RegisterButtonCallback();
        }

        void MainMenuUIController::CreateImages()
        {
            images.push_back(new ImageView());
            images.push_back(new ImageView());
        }

        void MainMenuUIController::CreateButtons()
        {
            buttons.push_back(new ButtonView());
            buttons.push_back(new ButtonView());
            buttons.push_back(new ButtonView());
        }

        void MainMenuUIController::InitializeImages()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

            images[0]->Initialize(Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
            images[0]->SetImageAlpha(backgroundAlpha);

            images[1]->Initialize(Config::titleNameTexturePath, titleNameSpriteWidth, titleNameSpriteHeight, titleNamePosition);
        }

        void MainMenuUIController::InitializeButtons()
        {
            buttons[0]->Initialize("Play Button", Config::playButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, playButtonYPosition));
            buttons[1]->Initialize("Instructions Button", Config::instructionsButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, instructionsButtonYPosition));
            buttons[2]->Initialize("Quit Button", Config::quitButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, quitButtonYPosition));

            for (auto& button : buttons)
            {
                button->SetCentreAligned();
            }
        }

        void MainMenuUIController::RegisterButtonCallback()
        {
            buttons[0]->RegisterCallbackFuntion(std::bind(&MainMenuUIController::PlayButtonCallback, this));
            buttons[1]->RegisterCallbackFuntion(std::bind(&MainMenuUIController::InstructionsButtonCallback, this));
            buttons[2]->RegisterCallbackFuntion(std::bind(&MainMenuUIController::QuitButtonCallback, this));
        }

        void MainMenuUIController::PlayButtonCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            GameService::SetGameState(GameState::GAMEPLAY);
        }

        void MainMenuUIController::InstructionsButtonCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            GameService::SetGameState(GameState::INSTRUCTIONS);
        }

        void MainMenuUIController::QuitButtonCallback()
        {
            ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->close();
        }

        void MainMenuUIController::Update()
        {
            for(auto & image : images)
            {
                image->Update();
            }

            for (auto& button : buttons)
            {
                button->Update();
            }
        }

        void MainMenuUIController::Render()
        {
            for (auto& image : images)
            {
                image->Render();
            }

            for (auto& button : buttons)
            {
                button->Render();
            }
        }

        void MainMenuUIController::Show()
        {
            for (auto& image : images)
            {
                image->Show();
            }

            for (auto& button : buttons)
            {
                button->Show();
            }

            ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
        }

        void MainMenuUIController::Destroy()
        {
            for (auto& image : images)
            {
                delete(image);
            }
            images.clear();

            for (auto& button : buttons)
            {
                delete(button);
            }
            buttons.clear();
        }
    }
}
