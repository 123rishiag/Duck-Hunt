#pragma once
#include "../../Header/UI/UIElement/ImageView.h"
#include <functional>

namespace UI
{
	namespace UIElement
	{
		class ButtonView : public ImageView
		{
		private:
			// Define a function pointer type for the callback function
			using CallbackFunction = std::function<void()>;

			// Store the callback function
			CallbackFunction callbackFunction = nullptr;

			void PrintButtonClicked();

		protected:
			sf::String buttonTitle;

			virtual void HandleButtonInteraction();
			virtual bool ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition);

		public:
			ButtonView();
			virtual ~ButtonView();

			void Initialize(sf::String title, sf::String texturePath, float buttonWidth, float buttonHeight, sf::Vector2f position);
			void UpdateContent() override;
			void RenderContent() override;

			void RegisterCallbackFuntion(CallbackFunction buttonCallback);
		};
	}
}