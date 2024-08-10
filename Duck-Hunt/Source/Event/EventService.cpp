#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
namespace Event {
    using namespace Global;
    EventService::EventService() 
    { 
        gameWindow = nullptr; 
    }

    EventService::~EventService() = default; // calls the default destructor

    void EventService::Initialize()
    {
        gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
    }

    void EventService::Update()
    {
        ProcessEvents();
        UpdateMouseButtonsState(leftMouseButtonState, sf::Mouse::Left); // Regularly checking mouse events
        UpdateMouseButtonsState(rightMouseButtonState, sf::Mouse::Right); // Regularly checking keyboard events
    }

    void EventService::ProcessEvents()
    {
        if (IsGameWindowOpen()) {
            while (gameWindow->pollEvent(gameEvent)) {
                // Check for window closure
                if (GameWindowWasClosed() || HasQuitGame())
                {
                    gameWindow->close();
                }
            }
        }
    }

    // Template function to update the state of any button type (mouse or keyboard)
    template<typename ButtonType, typename IsButtonPressedFunc>
    void EventService::UpdateButtonState(ButtonState& currentButtonState, ButtonType buttonType, IsButtonPressedFunc isButtonPressed)
    {
        if (isButtonPressed(buttonType))
        {
            switch (currentButtonState)
            {
            case ButtonState::RELEASED:
                currentButtonState = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                currentButtonState = ButtonState::HELD;
                break;
            }
        }
        else
        {
            currentButtonState = ButtonState::RELEASED;
        }
    }

    // Usage for mouse buttons
    void EventService::UpdateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton)
    {
        // to pass the "is button pressed" logic as a callable function
        auto isButtonPressedLambda = [](sf::Mouse::Button button) 
            {
                return sf::Mouse::isButtonPressed(button);
            };
        UpdateButtonState(currentButtonState, mouseButton, isButtonPressedLambda);
    }

    // Usage for keyboard buttons
    void EventService::UpdateKeyboardButtonsState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton)
    {
        // to pass the "is key pressed" logic as a callable function
        auto isKeyPressedLambda = [](sf::Keyboard::Key key)
            {
                return sf::Keyboard::isKeyPressed(key);
            };

        UpdateButtonState(currentButtonState, keyboardButton, isKeyPressedLambda);
    }


    bool EventService::HasQuitGame() const { return (IsKeyboardEvent() && PressedEscapeKey()); } // only true if the ESC key is pressed and a keyboard event has been registered

    //checks for if a keyboard key has been pressed
    bool EventService::IsKeyboardEvent() const { return gameEvent.type == sf::Event::KeyPressed; }

    //control click on the SFML functions to see what they do internally
    bool EventService::PressedEscapeKey() const { return gameEvent.key.code == sf::Keyboard::Escape; }

    bool EventService::IsGameWindowOpen() const { return gameWindow != nullptr; }

    bool EventService::GameWindowWasClosed() const { return gameEvent.type == sf::Event::Closed; }

    bool EventService::PressedLeftMouseButton() const { return leftMouseButtonState == ButtonState::PRESSED; }

    bool EventService::PressedRightMouseButton() const { return rightMouseButtonState == ButtonState::PRESSED; }

    // to fetch live position of mouse on screen
    sf::Vector2f  EventService::GetMousePosition() const 
    {
        if (gameWindow)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*gameWindow);
            return sf::Vector2f(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
        }
        return sf::Vector2f(0.0f, 0.0f); // Return a default value if gameWindow is not set
    }

    // to manually close window
    void EventService::CloseWindow()
    {
        gameWindow->close();
    }
}