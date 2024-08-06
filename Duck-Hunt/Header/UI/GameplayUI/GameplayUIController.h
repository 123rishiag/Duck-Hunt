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
			const sf::Color textColor = sf::Color::White;

			const float scoreTextXPosition = 1650.f;
			const float scoreTextYPosition = 15.f;
			UI::UIElement::TextView* scoreText;

			const float waveTimeLeftTextXPosition = 1450.f;
			const float waveTimeLeftTextYPosition = 1000.f;
			UI::UIElement::TextView* waveTimeLeftText;

			const sf::Vector2f playerLivesPosition = sf::Vector2f(0.f, 0.f);
			const float playerLivesYOffset = 15.f;
			const float playerLivesXOffset = 30.f;
			const float playerLivesSpacing = 60.f;
			const float playerLivesSpriteWidth = 50.f;
			const float playerLivesSpriteHeight = 50.f;
			UI::UIElement::ImageView* playerLivesImage;

			const sf::Vector2f playerAmmoPosition = sf::Vector2f(800.f, 0.f);
			const float playerAmmoYOffset = 15.f;
			const float playerAmmoXOffset = 30.f;
			const float playerAmmoSpacing = 20.f;
			const float playerAmmoSpriteWidth = 50.f;
			const float playerAmmoSpriteHeight = 50.f;
			UI::UIElement::ImageView* playerAmmoImage;
			const float playerCurrentBulletScaleFactor = 1.3f;

			const sf::Vector2f enemyPosition = sf::Vector2f(800.f, 900.f);
			const float enemyYOffset = 15.f;
			const float enemyXOffset = 30.f;
			const float enemySpacing = 60.f;
			const float enemySpriteWidth = 50.f;
			const float enemySpriteHeight = 50.f;
			UI::UIElement::ImageView* enemyImage;

			void CreateUIElements();
			void InitializeImage();
			void InitializeText();

			void UpdateScoreText();
			void UpdateWaveTimeLeftText();
			void DrawPlayerLives();
			void DrawPlayerAmmo();
			void DrawEnemy();

			void Destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;
		};
	}
}
