#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float buttonWidth = 400.f;
			const float buttonHeight = 140.f;

			const float playButtonYPosition = 500.f;
			const float instructionsButtonYPosition = 700.f;
			const float quitButtonYPosition = 900.f;

			const float backgroundAlpha = 230.f;

			UIElement::ImageView* backgroundImage;

			const sf::Vector2f titleNamePosition = sf::Vector2f(530.f, 50.f);
			const float titleNameSpriteWidth = 850.f;
			const float titleNameSpriteHeight = 350.f;
			UIElement::ImageView* titleNameImage;

			UIElement::ButtonView* playButton;
			UIElement::ButtonView* instructionsButton;
			UIElement::ButtonView* quitButton;

			void CreateImages();
			void CreateButtons();
			void InitializeBackgroundImage();
			void InitializeImages();
			void InitializeButtons();
			void RegisterButtonCallback();

			void PlayButtonCallback();
			void InstructionsButtonCallback();
			void QuitButtonCallback();

			void Destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;

		};
	}
}