#pragma once

#include <SFML/Graphics.hpp>

namespace Graphic {
	class GraphicService
	{
	private:

		const std::string gameWindowTitle = "Duck Hunt";

		const int gameWindowWidth = 1920;
		const int gameWindowHeight = 1080;

		const sf::Color windowColor = sf::Color::Blue;

		sf::VideoMode* videoMode; // ptr to video mode
		sf::RenderWindow* gameWindow; // ptr to a RenderWindow

		const int frameRate = 60; // Frame Rate is 60

		void SetVideoMode(); // Method for setting our video mode
		void OnDestroy(); // method to run when window is deleted

	public:
		GraphicService();
		~GraphicService(); //cleanup

		//method to create the game window. returns a pointer to an instance of the game window
		sf::RenderWindow* CreateGameWindow();

		void Initialize(); //lifecycle functions
		void Update(); //..
		void Render(); //..
		bool IsGameWindowOpen() const; //check if the window is open

		sf::RenderWindow* GetGameWindow() const; //getter for the game window instance
		sf::Color GetWindowColor() const;//get the color
	};
}