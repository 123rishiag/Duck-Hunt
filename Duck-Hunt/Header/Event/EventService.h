#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp> // Include for sf::Clock and sf::Time

namespace Event {

	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED,
	};

	class EventService
	{
	private:
		sf::Event gameEvent; //event variable
		sf::RenderWindow* gameWindow; //ptr to our game window

		ButtonState leftMouseButtonState;

		const float mouseHoldDurationInSeconds = 1.0f;

		sf::Clock mousePressClock; // Clock to track the duration of the mouse button press
		sf::Time mousePressDuration; // Time duration for which the mouse button has been pressed

		bool IsGameWindowOpen() const;
		bool GameWindowWasClosed() const; //for the condition we already had - the title bar cross.
		bool HasQuitGame() const; //for our new 'ESC' condition

		void UpdateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton);
		void UpdateKeyboardButtonsState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton);

	public:
		EventService();
		~EventService();

		void Initialize();
		void Update();
		void ProcessEvents(); // while window is open we will check for events

		bool PressedEscapeKey() const;
		bool IsKeyboardEvent() const;

		bool PressedLeftMouseButton() const;

		sf::Vector2f GetMousePosition() const;
	};
}