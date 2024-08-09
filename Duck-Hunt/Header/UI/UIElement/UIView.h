#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace UIElement
	{
		enum class UIState
		{
			VISIBLE,
			HIDDEN,
		};

		class UIView
		{
		protected:
			sf::RenderWindow* gameWindow;
			UIState uiState; // Holds the visibility status of UI

		public:
			UIView();
			virtual ~UIView();

			virtual void Initialize();
			virtual void Update();
			virtual void Render();

			virtual void Show();
			virtual void Hide();
		};
	}
}