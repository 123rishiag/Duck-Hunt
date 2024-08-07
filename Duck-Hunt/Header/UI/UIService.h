#pragma once
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController;
	}

	namespace MainMenu
	{
		class MainMenuUIController;
	}

	namespace Instruction
	{
		class InstructionUIController;
	}

	namespace GameplayUI
	{
		class GameplayUIController;
	}

	class UIService : public Interface::IUIController
	{
	private:

		SplashScreen::SplashScreenUIController* splashScreenUIController;
		MainMenu::MainMenuUIController* mainMenuController;
		Instruction::InstructionUIController* instructionController;
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

		void ShowMainMenu();
	};
}
