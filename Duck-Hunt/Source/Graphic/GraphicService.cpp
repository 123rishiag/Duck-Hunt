#include "../../Header/Graphic/GraphicService.h"

namespace Graphic {
	// Constructor: Initializes game window and video mode pointers to null.
	GraphicService::GraphicService() {
		gameWindow = nullptr; // Initializes game window pointer to null
		videoMode = nullptr; // Initializes video mode pointer to null
	}

	// Destructor: Cleans up resources by calling onDestroy.
	GraphicService::~GraphicService() {
		OnDestroy(); // Calls OnDestroy method to clean up resources
	}

	// Initializes the graphic service by creating a new game window.
	void GraphicService::Initialize() {
		gameWindow = CreateGameWindow(); // Assigns a new game window to the game_window pointer
		gameWindow->setFramerateLimit(frameRate);
	}

	// Creates a new SFML RenderWindow object with specified video mode and title.
	sf::RenderWindow* GraphicService::CreateGameWindow() {
		SetVideoMode(); // Sets up the video mode for the window
		return new sf::RenderWindow(*videoMode, gameWindowTitle, sf::Style::Fullscreen); // Creates and returns a new RenderWindow object
	}

	// Sets up the video mode for the game window using specified dimensions and system's color depth.
	void GraphicService::SetVideoMode() {
		videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
	}

	// Cleans up allocated memory for video mode and game window to avoid memory leaks.
	void GraphicService::OnDestroy() {
		delete(videoMode); // Deletes the video mode object
		delete(gameWindow); // Deletes the game window object
	}

	// Placeholder function for game update logic.
	void GraphicService::Update() { }

	// Placeholder function for game rendering logic.
	void GraphicService::Render() { }

	// Checks if the game window is currently open.
	bool GraphicService::IsGameWindowOpen() const {
		return gameWindow->isOpen(); // Returns the open status of the game window
	}

	// Returns a pointer to the game window object.
	sf::RenderWindow* GraphicService::GetGameWindow() const {
		return gameWindow;
	}

	// Returns the configured window background color.
	sf::Color GraphicService::GetWindowColor() const {
		return windowColor;
	}
}