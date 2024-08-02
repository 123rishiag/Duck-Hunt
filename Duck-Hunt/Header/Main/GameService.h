#pragma once

#include <SFML/Graphics.hpp>

namespace Global 
{
	class ServiceLocator;
}

namespace Main 
{
	enum class GameState //create the enum
	{
		BOOT,
		SPLASH_SCREEN,
		MAIN_MENU,
		INSTRUCTIONS,
		GAMEPLAY,
		CREDITS,
	};
	class GameService
	{
	private:
		Global::ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;
		static GameState currentState;

		void Initialize();		// Handles game initialization.
		void InitializeVariables();// Handles game initialization variables.
		void Destroy();			// Handles cleanup tasks.

		void ShowSplashScreen();

	public:
		GameService();			// Constructor for initializing the GameService object.
		~GameService();	    // Destructor for cleaning up resources upon object deletion.

		void Ignite();			// Initiates the game.
		void Update();			// Updates the game logic and game state.
		void Render();			// Renders each frame of the game.
		bool IsRunning() const;		// Checks if the game is currently running.

		sf::RenderWindow* GetGameWindow() const; // Getter for the game window instance

		static void SetGameState(GameState newState);
		static GameState GetGameState();
	};
}