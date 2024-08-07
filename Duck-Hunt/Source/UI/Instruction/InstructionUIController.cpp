#include "../../Header/UI/Instruction/InstructionUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Bullet/BulletConfig.h"
//#include "../../Header/Sound/SoundService.h"

namespace UI
{
    namespace Instruction
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Enemy;
        using namespace Bullet;
        //using namespace Sound;

        InstructionUIController::InstructionUIController()
        {
            CreateImage();
            CreateButton();
            CreateText();
        }

        InstructionUIController::~InstructionUIController()
        {
            Destroy();
        }

        void InstructionUIController::Initialize()
        {
            InitializeImage();
            InitializeButton();
            InitializeText();

            RegisterButtonCallback();
        }

        void InstructionUIController::CreateImage()
        {
            backgroundImage = new ImageView();

            bunkerImage = new ImageView();

            duckImage = new ImageView();
            powerDuckImage = new ImageView();

            pointBulletImage = new ImageView();
            areaBulletImage = new ImageView();
        }

        void InstructionUIController::CreateButton()
        {
            mainMenuButton = new ButtonView();
        }

        void InstructionUIController::CreateText()
        {
            controlsHeaderText = new TextView();
            controlsText = new TextView();

            enemiesHeaderText = new TextView();
            duckText = new TextView();
            powerDuckText = new TextView();

            bulletsHeaderText = new TextView();
            pointBulletText = new TextView();
            areaBulletText = new TextView();
        }

        void InstructionUIController::InitializeImage()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
            backgroundImage->Initialize(Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
            backgroundImage->SetImageAlpha(backgroundAlpha);

            duckImage->Initialize(EnemyConfig::duckTexturePath, iconSize, iconSize, duckImagePosition);
            powerDuckImage->Initialize(EnemyConfig::powerDuckTexturePath, iconSize, iconSize, powerDuckImagePosition);

            pointBulletImage->Initialize(BulletConfig::pointBulletTexturePath, iconSize, iconSize, pointBulletImagePosition);
            areaBulletImage->Initialize(BulletConfig::areaBulletTexturePath, iconSize, iconSize, areaBulletImagePosition);

        }

        void InstructionUIController::InitializeButton()
        {
            mainMenuButton->Initialize("Main Menu Button", Config::menuButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, mainMenuButtonYPosition));
            mainMenuButton->SetCentreAligned();
        }

        void InstructionUIController::InitializeText()
        {
            controlsHeaderText->Initialize(
                "Game Controls",
                controlsHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            controlsHeaderText->UnderlineText();
            controlsText->Initialize(
                "Left Click: Shoot \t\tRight Click: Change Bullets",
                controlsTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );

            enemiesHeaderText->Initialize(
                "Enemies",
                enemiesHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            enemiesHeaderText->UnderlineText();
            duckText->Initialize(
                "1. Duck --> Moves in same pattern, gives some score on dying.",
                duckTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
            powerDuckText->Initialize(
                "2. Power Duck --> Moves in random pattern, gives some score and kill nearby enemies on dying.",
                powerDuckTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );

            bulletsHeaderText->Initialize(
                "Bullets",
                bulletsHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            bulletsHeaderText->UnderlineText();
            pointBulletText->Initialize(
                "a) Point Bullet --> Kills enemies on which it is shot upon.",
                pointBulletTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
            areaBulletText->Initialize(
                "b) Area Bullet --> Kills enemies on a radius if shot upon.",
                areaBulletTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
        }

        void InstructionUIController::RegisterButtonCallback()
        {
            mainMenuButton->RegisterCallbackFuntion(std::bind(&InstructionUIController::MainMenuButtonCallback, this));
        }

        void InstructionUIController::MainMenuButtonCallback()
        {
            //ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            GameService::SetGameState(GameState::MAIN_MENU);
        }

        void InstructionUIController::Update()
        {
            backgroundImage->Update();

            bunkerImage->Update();

            duckImage->Update();
            powerDuckImage->Update();

            pointBulletImage->Update();
            areaBulletImage->Update();

            mainMenuButton->Update();

            controlsHeaderText->Update();
            controlsText->Update();

            enemiesHeaderText->Update();
            duckText->Update();
            powerDuckText->Update();

            bulletsHeaderText->Update();
            pointBulletText->Update();
            areaBulletText->Update();

        }

        void InstructionUIController::Render()
        {
            backgroundImage->Render();

            bunkerImage->Render();

            duckImage->Render();
            powerDuckImage->Render();

            pointBulletImage->Render();
            areaBulletImage->Render();

            mainMenuButton->Render();

            controlsHeaderText->Render();
            controlsText->Render();

            enemiesHeaderText->Render();
            duckText->Render();
            powerDuckText->Render();

            bulletsHeaderText->Render();
            pointBulletText->Render();
            areaBulletText->Render();
        }

        void InstructionUIController::Show()
        {
            backgroundImage->Show();

            bunkerImage->Show();

            duckImage->Show();
            powerDuckImage->Show();

            pointBulletImage->Show();
            areaBulletImage->Show();

            mainMenuButton->Show();

            controlsHeaderText->Show();
            controlsText->Show();

            enemiesHeaderText->Show();
            duckText->Show();
            powerDuckText->Show();

            bulletsHeaderText->Show();
            pointBulletText->Show();
            areaBulletText->Show();

            //ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
        }

        void InstructionUIController::Destroy()
        {
            delete(backgroundImage);

            delete(bunkerImage);

            delete(duckImage);
            delete(powerDuckImage);

            delete(pointBulletImage);
            delete(areaBulletImage);

            delete(mainMenuButton);

            delete(controlsHeaderText);
            delete(controlsText);

            delete(enemiesHeaderText);
            delete(duckText);
            delete(powerDuckText);

            delete(bulletsHeaderText);
            delete(pointBulletText);
            delete(areaBulletText);
        }
    }
}
