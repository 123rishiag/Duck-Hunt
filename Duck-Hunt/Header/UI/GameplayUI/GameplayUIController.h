#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
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

			const float scoreTextXPosition = 1600.f;
			const float scoreTextYPosition = 15.f;

			const float waveTimeLeftTextXPosition = 1450.f;
			const float waveTimeLeftTextYPosition = 1000.f;

			const float waveNameTextXPosition = 50.f;
			const float waveNameTextYPosition = 1000.f;
			sf::String waveNameString;

			const float waveInfoTextXPosition = 775.f;
			const float waveInfoTextYPosition = 450.f;

			const sf::Vector2f playerLivesPosition = sf::Vector2f(0.f, 0.f);
			const float playerLivesYOffset = 15.f;
			const float playerLivesXOffset = 30.f;
			const float playerLivesSpacing = 60.f;
			const float playerLivesSpriteWidth = 50.f;
			const float playerLivesSpriteHeight = 50.f;

			const sf::Vector2f playerAmmoPosition = sf::Vector2f(800.f, 0.f);
			const float playerAmmoYOffset = 15.f;
			const float playerAmmoXOffset = 30.f;
			const float playerAmmoSpacing = 20.f;
			const float playerAmmoSpriteWidth = 50.f;
			const float playerAmmoSpriteHeight = 50.f;
			const float playerCurrentBulletScaleFactor = 1.3f;

			const sf::Vector2f enemyPosition = sf::Vector2f(800.f, 900.f);
			const float enemyYOffset = 15.f;
			const float enemyXOffset = 30.f;
			const float enemySpacing = 60.f;
			const float enemySpriteWidth = 50.f;
			const float enemySpriteHeight = 50.f;

			std::vector<UI::UIElement::ImageView*> images;
			std::vector<UI::UIElement::TextView*> texts;

			void CreateUIElements();
			void InitializeImage();
			void InitializeText();

			void UpdateScoreText();
			void UpdateWaveTimeLeftText();
			void UpdateWaveNameText();
			void UpdateWaveInfoText();
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
