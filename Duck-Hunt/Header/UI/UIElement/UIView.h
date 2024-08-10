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

			virtual void UpdateContent();
			virtual void RenderContent();

		public:
			UIView();
			virtual ~UIView();

			virtual void Initialize();
			void Update();
			void Render();

			virtual void Show();
			virtual void Hide();
		};
	}
}