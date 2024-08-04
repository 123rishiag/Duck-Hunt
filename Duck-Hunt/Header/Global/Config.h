#pragma once
#include <SFML/Graphics.hpp>

namespace Global
{
	class Config
	{
	public:
		static const sf::String outscalLogoTexturePath;
		static const sf::String backgroundTexturePath;

		static const sf::String playerTexturePath;

		static const sf::String playerHealthCounterTexturePath;
		static const sf::String duckCounterTexturePath;
		static const sf::String playerBulletCounterTexturePath;

		static const sf::String playButtonTexturePath;
		static const sf::String instructionsButtonTexturePath;
		static const sf::String quitButtonTexturePath;
		static const sf::String menuButtonTexturePath;

		static const sf::String bubbleBobbleFontPath;
		static const sf::String dsDigibFontPath;
		static const sf::String openSansFontPath;
	};
}
