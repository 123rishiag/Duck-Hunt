#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

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
		sf::Event gameEvent; // event variable
		sf::RenderWindow* gameWindow; // ptr to our game window

		ButtonState leftMouseButtonState;
		ButtonState rightMouseButtonState;

		bool IsGameWindowOpen() const;
		bool GameWindowWasClosed() const; // for the condition we already had - the title bar cross.
		bool HasQuitGame() const; // for our new 'ESC' condition

		// Template function to update the state of any button type (mouse or keyboard)
		template<typename ButtonType, typename IsButtonPressedFunc>
		void UpdateButtonState(ButtonState& currentButtonState, ButtonType buttonType, IsButtonPressedFunc isButtonPressed);

		void UpdateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton);
		void UpdateKeyboardButtonsState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton);

	public:
		EventService();
		~EventService();

		void Initialize();
		void Update();
		void ProcessEvents(); // while window is open we will check for events

		bool PressedEscapeKey() const; // to check if the escape key is pressed
		bool IsKeyboardEvent() const; // to check if keyboard event is triggered

		bool PressedLeftMouseButton() const;
		bool PressedRightMouseButton() const;

		sf::Vector2f GetMousePosition() const; // to fetch live position of mouse on screen

		void CloseWindow(); // to manually close window
	};
}