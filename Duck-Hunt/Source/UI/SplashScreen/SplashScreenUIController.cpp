#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
//#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace UI
{
    namespace SplashScreen
    {
        using namespace Main;
        using namespace Graphic;
        using namespace Global;
        using namespace UIElement;
        //using namespace Sound;

        SplashScreenUIController::SplashScreenUIController()
        {
            backgroundImage = new ImageView();
            outscalLogoView = new AnimatedImageView();
        }

        SplashScreenUIController::~SplashScreenUIController()
        {
            delete (outscalLogoView);
            delete (backgroundImage);
        }

        void SplashScreenUIController::Initialize()
        {
            InitializeBackgroundImage();
            InitializeOutscalLogo();
        }

        void SplashScreenUIController::Update()
        {
            backgroundImage->Update();
            outscalLogoView->Update();
        }

        void SplashScreenUIController::Render()
        {
            backgroundImage->Render();
            outscalLogoView->Render();
        }

        void SplashScreenUIController::Show()
        {
            backgroundImage->Show();
            outscalLogoView->PlayAnimation(AnimationType::FADE_IN, logoAnimationDuration, std::bind(&SplashScreenUIController::FadeInAnimationCallback, this));
        }

        void SplashScreenUIController::InitializeBackgroundImage()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
            backgroundImage->Initialize(Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
            backgroundImage->SetImageAlpha(backgroundAlpha);
            ServiceLocator::GetInstance()->GetAnimationService()->SpawnAnimation(sf::Vector2f(gameWindow->getSize().x - loadIconWidth, gameWindow->getSize().y - loadIconHeight), Animation::AnimationType::LOAD);
        }

        void SplashScreenUIController::InitializeOutscalLogo()
        {
            sf::Vector2f position = GetLogoPosition();
            outscalLogoView->Initialize(Config::outscalLogoTexturePath, logoWidth, logoHeight, position);
        }

        void SplashScreenUIController::FadeInAnimationCallback()
        {
            outscalLogoView->PlayAnimation(AnimationType::FADE_OUT, logoAnimationDuration, std::bind(&SplashScreenUIController::FadeOutAnimationCallback, this));
        }

        void SplashScreenUIController::FadeOutAnimationCallback()
        {
            //ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
            GameService::SetGameState(GameState::GAMEPLAY);
        }

        sf::Vector2f SplashScreenUIController::GetLogoPosition()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

            float xPosition = (gameWindow->getSize().x - logoWidth) / 2.0f;
            float yPosition = (gameWindow->getSize().y - logoHeight) / 2.0f;

            return sf::Vector2f(xPosition, yPosition);
        }
    }
}