#pragma once
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController;
	}

	class UIService : public Interface::IUIController
	{
	private:
		GameplayUI::GameplayUIController* gameplayUIController;

		IUIController* GetCurrentUIController();

		void CreateControllers();
		void InitializeControllers();
		void Destroy();

	public:
		UIService();
		~UIService();

		void Initialize() override;
		void Update() override;
		void Render() override;
		void Show() override;
	};
}
