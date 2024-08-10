#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include <array>

namespace UI
{
	class UIService : public Interface::IUIController
	{
	private:

		std::array<Interface::IUIController*, 4> uiControllers;

		IUIController* GetCurrentUIController(); // To fetch the current controller

		void CreateControllers(); // To create all UI Controllers
		void InitializeControllers(); // To initialize all UI Controllers
		void Destroy();

	public:
		UIService();
		~UIService();

		void Initialize() override;
		void Update() override;
		void Render() override;
		void Show() override;

		void ShowMainMenu(); // Method to show Main Menu
	};
}
