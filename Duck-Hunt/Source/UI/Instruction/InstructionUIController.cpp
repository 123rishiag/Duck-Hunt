#include "../../Header/UI/Instruction/InstructionUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Sound/SoundService.h"

namespace UI
{
    namespace Instruction
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Enemy;
        using namespace Bullet;
        using namespace Sound;

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
            images.push_back(new ImageView()); // backgroundImage
            images.push_back(new ImageView()); // duckImage
            images.push_back(new ImageView()); // powerDuckImage
            images.push_back(new ImageView()); // pointBulletImage
            images.push_back(new ImageView()); // areaBulletImage
        }

        void InstructionUIController::CreateButton()
        {
            buttons.push_back(new ButtonView()); // mainMenuButton
        }

        void InstructionUIController::CreateText()
        {
            texts.push_back(new TextView()); // controlsHeaderText
            texts.push_back(new TextView()); // controlsText
            texts.push_back(new TextView()); // enemiesHeaderText
            texts.push_back(new TextView()); // duckText
            texts.push_back(new TextView()); // powerDuckText
            texts.push_back(new TextView()); // bulletsHeaderText
            texts.push_back(new TextView()); // pointBulletText
            texts.push_back(new TextView()); // areaBulletText
        }

        void InstructionUIController::InitializeImage()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
            images[0]->Initialize(Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
            images[0]->SetImageAlpha(backgroundAlpha);

            images[1]->Initialize(EnemyConfig::duckTexturePath, iconSize, iconSize, duckImagePosition);
            images[2]->Initialize(EnemyConfig::powerDuckTexturePath, iconSize, iconSize, powerDuckImagePosition);

            images[3]->Initialize(BulletConfig::pointBulletTexturePath, iconSize, iconSize, pointBulletImagePosition);
            images[4]->Initialize(BulletConfig::areaBulletTexturePath, iconSize, iconSize, areaBulletImagePosition);
        }

        void InstructionUIController::InitializeButton()
        {
            buttons[0]->Initialize("Main Menu Button", Config::menuButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, mainMenuButtonYPosition));
            buttons[0]->SetCentreAligned();
        }

        void InstructionUIController::InitializeText()
        {
            texts[0]->Initialize(
                "Game Controls",
                controlsHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            texts[0]->UnderlineText();

            texts[1]->Initialize(
                "Left Click --> Shoot \t\tRight Click --> Change Bullets",
                controlsTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );

            texts[2]->Initialize(
                "Enemies",
                enemiesHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            texts[2]->UnderlineText();

            texts[3]->Initialize(
                "1. Duck --> Moves in same pattern, gives some score on dying.",
                duckTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );

            texts[4]->Initialize(
                "2. Power Duck --> Moves in random pattern, gives some score and kill nearby enemies on dying.",
                powerDuckTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );

            texts[5]->Initialize(
                "Bullets",
                bulletsHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            texts[5]->UnderlineText();

            texts[6]->Initialize(
                "a) Point Bullet --> Kills enemies on which it is shot upon.",
                pointBulletTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );

            texts[7]->Initialize(
                "b) Area Bullet --> Kills enemies on a radius if shot upon.",
                areaBulletTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
        }

        void InstructionUIController::RegisterButtonCallback()
        {
            buttons[0]->RegisterCallbackFuntion(std::bind(&InstructionUIController::MainMenuButtonCallback, this));
        }

        void InstructionUIController::MainMenuButtonCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            GameService::SetGameState(GameState::MAIN_MENU);
        }

        void InstructionUIController::Update()
        {
            for (auto& image : images)
            {
                image->Update();
            }

            for (auto& button : buttons)
            {
                button->Update();
            }

            for (auto& text : texts)
            {
                text->Update();
            }
        }

        void InstructionUIController::Render()
        {
            for (auto& image : images)
            {
                image->Render();
            }

            for (auto& button : buttons)
            {
                button->Render();
            }

            for (auto& text : texts)
            {
                text->Render();
            }
        }

        void InstructionUIController::Show()
        {
            for (auto& image : images)
            {
                image->Show();
            }

            for (auto& button : buttons)
            {
                button->Show();
            }

            for (auto& text : texts)
            {
                text->Show();
            }

            ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
        }

        void InstructionUIController::Destroy()
        {
            for (auto& image : images)
            {
                delete image;
            }
            images.clear();

            for (auto& button : buttons)
            {
                delete button;
            }
            buttons.clear();

            for (auto& text : texts)
            {
                delete text;
            }
            texts.clear();
        }
    }
}
