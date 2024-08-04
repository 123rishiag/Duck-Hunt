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
		static const sf::String playerHealthTexturePath;
		static const sf::String duckTexturePath;
		static const sf::String powerDuckTexturePath;
		static const sf::String pointBulletTexturePath;
		static const sf::String areaBulletTexturePath;

		static const sf::String playButtonTexturePath;
		static const sf::String instructionsButtonTexturePath;
		static const sf::String quitButtonTexturePath;
		static const sf::String menuButtonTexturePath;

		static const sf::String bubbleBobbleFontPath;
		static const sf::String dsDigibFontPath;
		static const sf::String openSansFontPath;
	};
}
