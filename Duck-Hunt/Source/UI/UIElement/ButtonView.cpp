#include "../../Header/UI/UIElement/ButtonView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"

namespace UI
{
    namespace UIElement
    {
        using namespace Event;
        using namespace Global;

        ButtonView::ButtonView() = default;

        ButtonView::~ButtonView() = default;

        void ButtonView::Initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position)
        {
            ImageView::Initialize(texture_path, button_width, button_height, position);
            buttonTitle = title;
        }

        void ButtonView::RegisterCallbackFuntion(CallbackFunction buttonCallback)
        {
            callbackFunction = buttonCallback;
        }

        void ButtonView::Update()
        {
            ImageView::Update();

            if (uiState == UIState::VISIBLE)
            {
                HandleButtonInteraction();
            }
        }

        void ButtonView::Render()
        {
            ImageView::Render();
        }

        void ButtonView::HandleButtonInteraction()
        {
            sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));

            if (ClickedButton(&imageSprite, mousePosition))
            {
                if (callbackFunction) callbackFunction();
            }
        }

        bool ButtonView::ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition)
        {
            return ServiceLocator::GetInstance()->GetEventService()->PressedLeftMouseButton() &&
                buttonSprite->getGlobalBounds().contains(mousePosition);
        }

        void ButtonView::PrintButtonClicked()
        {
            printf("Clicked %s\n", buttonTitle.toAnsiString().c_str());
        }
    }
}