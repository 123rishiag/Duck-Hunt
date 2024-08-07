#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
    namespace Instruction
    {
        class InstructionUIController : public Interface::IUIController
        {
        private:
            const float backgroundAlpha = 230.f;

            const float buttonWidth = 400.f;
            const float buttonHeight = 140.f;

            const int iconSize = 60;
            const float imageTextSpacing = 15.f;
            const float segmentSpacing = 45.f;
            const int instructionFontSize = 36;
            const sf::Color instructionTextColor = sf::Color(224, 255, 255);

            const sf::Vector2f controlsHeaderTextPosition = sf::Vector2f(50.f, 20.f);
            const sf::Vector2f controlsTextPosition = sf::Vector2f(50.f, 2 * segmentSpacing);

            const sf::Vector2f enemiesHeaderTextPosition = sf::Vector2f(50.f, controlsTextPosition.y + iconSize + segmentSpacing);
            const sf::Vector2f duckImagePosition = sf::Vector2f(50.f, enemiesHeaderTextPosition.y + 2 * segmentSpacing);
            const sf::Vector2f duckTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, enemiesHeaderTextPosition.y + 2 * segmentSpacing);
            const sf::Vector2f powerDuckImagePosition = sf::Vector2f(50.f, duckImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f powerDuckTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, duckImagePosition.y + iconSize + segmentSpacing);

            const sf::Vector2f bulletsHeaderTextPosition = sf::Vector2f(50.f, powerDuckImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f pointBulletImagePosition = sf::Vector2f(50.f, bulletsHeaderTextPosition.y + 2 * segmentSpacing);
            const sf::Vector2f pointBulletTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, bulletsHeaderTextPosition.y + 2 * segmentSpacing);
            const sf::Vector2f areaBulletImagePosition = sf::Vector2f(50.f, pointBulletImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f areaBulletTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, pointBulletImagePosition.y + iconSize + segmentSpacing);

            float mainMenuButtonYPosition = 850.f;


            UIElement::ImageView* backgroundImage;

            UIElement::ImageView* bunkerImage;

            UIElement::ImageView* duckImage;
            UIElement::ImageView* powerDuckImage;

            UIElement::ImageView* pointBulletImage;
            UIElement::ImageView* areaBulletImage;

            UIElement::ButtonView* mainMenuButton;

            UIElement::TextView* controlsHeaderText;
            UIElement::TextView* controlsText;

            UIElement::TextView* enemiesHeaderText;
            UIElement::TextView* duckText;
            UIElement::TextView* powerDuckText;

            UIElement::TextView* bulletsHeaderText;
            UIElement::TextView* pointBulletText;
            UIElement::TextView* areaBulletText;

            void CreateImage();
            void CreateButton();
            void CreateText();

            void InitializeImage();
            void InitializeButton();
            void InitializeText();

            void RegisterButtonCallback();
            void MainMenuButtonCallback();

            void Destroy();

        public:
            InstructionUIController();
            ~InstructionUIController();

            void Initialize() override;
            void Update() override;
            void Render() override;
            void Show() override;
        };
    }
}
