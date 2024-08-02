#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float fontSize = 50.f;

			const float textYPosition = 15.f;
			const float scoreTextXPosition = 1650.f;

			const float playerLivesYOffset = 15.f;
			const float playerLivesXOffset = 30.f;
			const float playerLivesSpacing = 60.f;

			const float playerhealthCounterSpriteWidth = 50.f;
			const float playerhealthCounterSpriteHeight = 50.f;

			const sf::Color textColor = sf::Color::White;

			UI::UIElement::ImageView* playerhealthCounterImage;
			UI::UIElement::TextView* scoreText;

			void CreateUIElements();
			void InitializeImage();
			void InitializeText();

			void Destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;

			void UpdateScoreText();
			void DrawPlayerLives();
		};
	}
}
