#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
//#include "../../Header/Sound/SoundService.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        //using namespace Sound;

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
            InitializeBackgroundImage();
            InitializeImages();
            InitializeButtons();
            RegisterButtonCallback();
        }

        void MainMenuUIController::CreateImages()
        {
            backgroundImage = new ImageView();
            titleNameImage = new ImageView();
        }

        void MainMenuUIController::CreateButtons()
        {
            playButton = new ButtonView();
            instructionsButton = new ButtonView();
            quitButton = new ButtonView();
        }

        void MainMenuUIController::InitializeBackgroundImage()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
            backgroundImage->Initialize(Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
            backgroundImage->SetImageAlpha(backgroundAlpha);
        }

        void MainMenuUIController::InitializeImages()
        {
            titleNameImage->Initialize(Config::titleNameTexturePath, titleNameSpriteWidth, titleNameSpriteHeight, titleNamePosition);
        }

        void MainMenuUIController::InitializeButtons()
        {
            playButton->Initialize("Play Button", Config::playButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, playButtonYPosition));
            instructionsButton->Initialize("Instructions Button", Config::instructionsButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, instructionsButtonYPosition));
            quitButton->Initialize("Quit Button", Config::quitButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, quitButtonYPosition));

            playButton->SetCentreAligned();
            instructionsButton->SetCentreAligned();
            quitButton->SetCentreAligned();
        }

        void MainMenuUIController::RegisterButtonCallback()
        {
            playButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::PlayButtonCallback, this));
            instructionsButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::InstructionsButtonCallback, this));
            quitButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::QuitButtonCallback, this));
        }

        void MainMenuUIController::PlayButtonCallback()
        {
            //ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            GameService::SetGameState(GameState::GAMEPLAY);
        }

        void MainMenuUIController::InstructionsButtonCallback()
        {
            //ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            GameService::SetGameState(GameState::INSTRUCTIONS);
        }

        void MainMenuUIController::QuitButtonCallback()
        {
            ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->close();
        }

        void MainMenuUIController::Update()
        {
            backgroundImage->Update();
            titleNameImage->Update();
            playButton->Update();
            instructionsButton->Update();
            quitButton->Update();
        }

        void MainMenuUIController::Render()
        {
            backgroundImage->Render();
            titleNameImage->Render();
            playButton->Render();
            instructionsButton->Render();
            quitButton->Render();
        }

        void MainMenuUIController::Show()
        {
            backgroundImage->Show();
            titleNameImage->Show();
            playButton->Show();
            instructionsButton->Show();
            quitButton->Show();

            //ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
        }

        void MainMenuUIController::Destroy()
        {
            delete (playButton);
            delete (instructionsButton);
            delete (quitButton);
            delete (titleNameImage);
            delete (backgroundImage);
        }
    }
}
